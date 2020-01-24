#include<iostream>
#include"List.h"
using namespace std;
//empty size swap emplace

template<typename T> 
class queue
{
	list<T> li;
	int size;
	public:
		queue();
		void push(T);
		void pop();
		T* front();
		T* back();
		bool empty();
		void display();
};

template<typename T>
queue<T>::queue()
{
	size=0;
}
template<typename T>
void queue<T>::push(T d)
{
	li.push_back(d);
	size++;	
}

template<typename T>
void queue<T>::pop()
{
	if(size!=0)
	{
		size--;
		li.pop_front();
	}	
}
template<typename T>
void queue<T>::display()
{
	li.display();
}

