#pragma once
#include<iostream>

template<class T =size_t,size_t _MemoryPoolSize = 1024>
class MemoryPool {
public:
	//初始化
	MemoryPool() 
		:_freeList(nullptr)
		,_sizeT(std::max(sizeof(T),sizeof(void*)))
	{
		newMemoryPool();
	}

	
	//从内存池申请空间
	T* newMemory(){
		T* ret = nullptr;
		if (_freeList) { // 自由空间链表不为空
			ret = (T*)_freeList; // 将自由链表空间分配出去
			_freeList = *((void**)_freeList); // 自由链表后移
		}
		else {
			if (_freeSize == 0) { // 无未分配空间
				newMemoryPool(); // 申请新内存池空间
			}
			ret = (T*)_MemoryPoolFront;	// 将内存池首部空间分配出去
			_MemoryPoolFront += _sizeT; // 内存池空间首部指针后移
			_freeSize--; //内存池未分配空间标记减少
		}
		return ret;
	};

	//将空间还给内存池(加入_freeList)
	void deleteMemory(T* obj) {
		obj->~T(); // 销毁对象
		// 头插入自由链表
		*((void**)obj) = _freeList;
		_freeList = obj;
	};
	/*void print() {
		std::cout << delnum  << ' ' << newFree << ' ' << newFront  << ' ' << newPool << std::endl;
	}*/
private:
	//申请新的内存池
	void newMemoryPool() {
		//newPool++;
		_MemoryPoolFront = (char*)malloc(_sizeT * _MemoryPoolSize);
		if (_MemoryPoolFront == nullptr) { // 申请空间失败时
			throw std::bad_alloc();	// 返回bad_alloc异常
		}
		_freeSize = _MemoryPoolSize; //修改内存池未分配空间大小标记
	}

	void* _freeList; // 自由空间链表
	size_t _freeSize; //内存池未分配空间大小标记
	char* _MemoryPoolFront; // 内存池未分配空间头
	int _sizeT;

	/*int delnum = 0;
	int newFree = 0;
	int newFront = 0;
	int newPool = 0;*/
};