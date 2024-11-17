#pragma once
#include "MemoryPool.hpp"
#include <iostream>
#include <ctime>
#include <vector>

// 每轮申请释放多少次
#define N 1000000

struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{
	}
};

void TestObjectPool()
{
	// 申请释放的轮次
	const size_t Rounds = 5;


	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}

	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	MemoryPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.newMemory());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.deleteMemory(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	std::cout << "new cost time:" << end1 - begin1 << std::endl;
	std::cout << "object pool cost time:" << end2 - begin2 << std::endl;
}

void Mytest() {
	MemoryPool<int, 100> memoryPool;

	std::vector<int*> vi;

	srand(std::time(0));

	for (int i = 0; i < N; i++) {
		int flag = rand() % 2;
		if (flag == 1) {
			vi.push_back(memoryPool.newMemory());
		}
		else if (!vi.empty()) {
			memoryPool.deleteMemory(vi.back());
			vi.pop_back();
		}
		//memoryPool.print();
	}
}

int main() {
	TestObjectPool();

	return 0;
}