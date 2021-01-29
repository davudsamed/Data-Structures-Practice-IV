/**
* @file B171210007_1A_FinalÖdevi
* @description Stack sınıfı başlık dosyası
* @course 1. Öğretim A Grubu
* @assignment Final Ödevi
* @date 1.09.2020
* @author Davud Samed Tombul
*/
#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <algorithm>

using namespace std;

class Stack
{
private:
	string *items;
	int head;
	int length;
	int capacity;
	bool IsFull();
	void Reserve(int);

public:
	Stack();
	bool IsEmpty();
	void Push(const string &);
	void Pop();
	const string &Top();
	void StackYazdir(Stack *);
	void Clear();
	~Stack();
};
#endif