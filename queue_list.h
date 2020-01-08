#include<iostream>
#include"slist.h"
using namespace std;

template<typename T> 
class queue
{
	list<T> li;
	int size;
	public:
		queue();
		void push(T);
		T pop();
		T* front();
		T* back();
		
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
T queue<T>::pop()
{
	if(size!=0)
	{
		size--;
		return li.pop_back();
	}
	
}
