/**
* @file B171210007_1A_FinalÖdevi
* @description Stack sınıfı kaynak dosyası
* @course 1. Öğretim A Grubu
* @assignment Final Ödevi
* @date 1.09.2020
* @author Davud Samed Tombul
*/
#include "Stack.hpp"
#include <iostream>
#include <math.h>

using namespace std;

bool Stack::IsFull()
{
	return length == capacity;
}
void Stack::Reserve(int capacity)
{
	string *tmp = new string[capacity];
	for (int i = 0; i < length; i++)
	{
		tmp[i] = items[i];
	}
	if (items != NULL)
		delete[] items;
	items = tmp;
	this->capacity = capacity;
}
Stack::Stack()
{
	items = NULL;
	head = -1;
	length = 0;
	capacity = 0;
}
bool Stack::IsEmpty()
{
	return head == -1;
}
void Stack::Push(const string &obj)
{
	if (IsFull())
	{
		Reserve(max(1, 2 * capacity));
	}
	head++;
	items[head] = obj;
	length++;
}
void Stack::Pop()
{
	if (IsEmpty())
		return;
	head--;
	length--;
}
const string &Stack::Top()
{
	if (IsEmpty())
		return NULL;
	return items[head];
}

void Stack::StackYazdir(Stack *stack)
{
	cout << "Stack: ";
	while (!stack->IsEmpty())
	{
		cout << stack->Top() << " ";
		stack->Pop();
	}
	cout << endl;
}

void Stack::Clear()
{
	head = -1;
	length = 0;
}

Stack::~Stack()
{
	if (items != NULL)
		delete[] items;
	items = NULL;
}