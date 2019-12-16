#include<iostream>
#include"NODE.h"
using namespace std;
/*template<typename T>
class node
{
		T data;
		node<T> * next;
	public:
		node()
		{
			next=NULL;
		}
		node(T d)
		{
			data=d;
			next=NULL;
		}
		node(T d, node *t)
		{
			data=d;
			next=t;
		}
		~node(){}
		void setdata(T d)
		{
			data=d;
		}
		T getdata(){return data;
		}
		node* getnext(){return next;
		}
		void setnext(node*t){next=t;
		}
		void setnull(){next=NULL;
		}
};*/
template<typename T>
class stack
{
		node<T> * tp;
		int cnt;
	public:
		stack()
		{
			top=NULL;
			cnt=0;
		}
		~stack();
		void push(T);
		int size();
		T* pop();
		T top();
		bool empty(){return (top==NULL);
		}
		void menu();
		void display();
};
template<typename T>
int stack<T>::size()
{
	return cnt;
}
template<typename T>
void stack<T>::push(T d)
{
	top=new node<T>(d,top);
	cnt++;
}
template<typename T>
T* stack<T>::pop()
{
	int d;
	if(top==NULL)
	{
		cout<<"Underflow";
		d=-1;
	}
	else
	{
		node<T> *a=tp;
		d=a->getdata();
		top=a->getnext();
		delete a;
		cnt--;
	}
	return d;
}
template<typename T>
T stack<T>::top()
{
	node<T> *a=tp;
	return a->getdata();
}
template<typename T>
void stack<T>::menu()
{
	int opt;
	T d;
	while(1)
	{
		cout<<"\nMenu\n1.Push\n2.Pop\n3.Stack top\n4.Display\n5.Size of stack\n6.Exit";
		cin>>opt;
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				cout<<"\nEnter data:";
				cin>>d;
				push(d);
				break;
			case 2:
				d=pop();
				cout<<d;
				break;
			case 3:
				if(empty())
					cout<<"\nUnderflow";
				else
					cout<<top();
				break;
			case 4:
				display();
				break;
			case 5:
				cout<<size();
				break;
		}
	}
}
template<typename T>
void stack<T>::display()
{
	node<T> *a=tp;
	if(a==NULL)
		cout<<"\nUnderflow";
	else
	{
		while(a!=NULL)
		{
			cout<<a->getdata()<<"\n";
			a=a->getnext();
		}
	}
}
template<typename T>
stack<T>::~stack()
{
	node<T> *a=tp;
	while(a!=NULL)
	{
		top=a->getnext();
		delete a;
		a=tp;
	}
}
