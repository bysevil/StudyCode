#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string>
namespace bysevil
{
    class string
    {
        friend std::ostream& operator<<(std::ostream& _cout, const bysevil::string& s);
        friend std::istream& operator>>(std::istream& _cin, bysevil::string& s);
    public:
        typedef char* iterator;
        /////////////////////////////////////////////////////////////
        string(const char* str = "");
        string(const string& s);
        string& operator=(const string& s);
        ~string();
        /////////////////////////////////////////////////////////////
        // iterator
        iterator begin()const;
        iterator end()const;
        /////////////////////////////////////////////////////////////
        // modify
        void push_back(char c);
        string& operator+=(char c);
        void append(const char* str);
        string& operator+=(const char* str);
        void clear();
        void swap(string& s);
        const char* c_str()const;
        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const;
        size_t capacity()const;
        bool empty()const;
        void resize(size_t n, char c = '\0');
        void reserve(size_t n);
        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index);
        const char& operator[](size_t index)const;
        /////////////////////////////////////////////////////////////
        //relational operators
        bool operator<(const string& s);
        bool operator<=(const string& s);
        bool operator>(const string& s);
        bool operator>=(const string& s);
        bool operator==(const string& s);
        bool operator!=(const string& s);
        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const;
        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const;
        //在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);
        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len);
    private:
        char* _str = nullptr;
        size_t _capacity = 0;
        size_t _size = 0;
    };
};