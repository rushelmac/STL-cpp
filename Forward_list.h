#include<iostream>
#include<cstdlib>
#include "algorithm.h"
using namespace std;
template<typename T>
class node
{
	T data;
	node<T> *next;
	//node<T> *prev;
	public:
		node()
		{
			data=0;
			next=NULL;
		//	prev=NULL;
		}
		node(T d)
		{
			data=d;
			//prev=NULL;
			next=NULL;
		}
		node(T d,node<T>*t1)
		{
			data=d;
			next=t1;
			//prev=t1;
		}
		~node(){}
		void setdata(T d)
		{
			data=d;
		}
		T getdata(){return data;}
		node<T>*getnext(){return next;}
		//node<T>*getprev(){return prev;}
		void setnext(node<T>*t2){next=t2;}
		void setnull(){next=NULL;}
	//	void setprev(node<T>*t1){prev=t1;}
	//	void setpnull(){prev=NULL;}
};
template<typename T>
class Iterator
{
	private:
	node<T>*itr;
	public:
		Iterator(){itr=NULL;}
		Iterator(node<T>* par){ itr=par;}
		T operator*(){return itr->getdata();}
		 Iterator operator++(int)
		{
			itr=itr->getnext();
			return *this;
		}
		Iterator operator++()
		{
			itr=itr->getnext();
			return *this;
		}
		/*Iterator operator--()
		{
			itr=itr->getprev();
			return *this;
		}*/
		
		bool operator==(const Iterator&k)
		{
			return itr==k.itr;
		}
		bool operator!=(const Iterator&k)
		{
			return itr!=k.itr;
		}
		node<T>* getNode()
		{
			return itr;
		}
};
template<typename T>			
class Forward_list:public Iterator<T>
{
	private:
		int cnt;
		node<T>* fr;
		//node<T>* rr;
	public:
	Forward_list(){
		fr=NULL;
		cnt=0;
	}
	~Forward_list(){}
	//void push_back(T);
	void push_front(T);
	void assign (int,T);
	void display();
	void pop_front();
	int empty();
	void erase(Iterator<T>);
	int size();
	Iterator<T>begin(){return fr;}
	T front();
	void insert(Iterator<T>,T);
	/*
	
	void pop_back();
	void assign(Iterator<T>,Iterator<T>);
	
	Iterator<T> end(){return rr->getnext();}
	//Iterator<T> rbegin(){return rr;}
	//Iterator<T> rend(){return fr;}
	
	T back();
	
	
	void remove(T val);
	
	void Sort();
	void unique();
	//void merge(Forward_list<T>&);*/
	
};

template<typename T>
void Forward_list<T>::push_front(T d)
{
	node<T>* a=new node<T>(d);
	
	if(fr==NULL)
	{
		fr=a;
		
	}
	else
	{
		//node<T>* b=ptr->getprev();
		//a->setnext(b);
		//b->setprev(a);
		a->setnext(fr);
			fr=a;
		//fr->setprev(a);
	}
	//ptr->setdata(ptr->getdata()+1);

	cnt++;
	return;
}
template<typename T>	  
void Forward_list<T>::display()
{
	node<T> *a=fr;
	std::cout<<"\n Forward_list:";
	if(a==NULL)
	{
		std::cout<<"\n Empty Forward_list<T>.";
	}
	else
	{
		while(a!=NULL)
		{
			std::cout<<a->getdata()<<" ";
			a=a->getnext();
		}
	}
}
//To assign elements to a Forward_list<T>.
template<typename T>
void Forward_list<T>::assign (int n,T val)
{
	fr=NULL;
	node<T>*rr;
	//node* a=new node(val);
	//setprev(a);
	for(int i=1;i<=n;i++)
	{
		node<T>* c=new node<T>(val);
		if(fr==NULL)
			fr=c;
		else
		{
			c->setnext(fr);
			
		}
		//ptr->setdata(ptr->getdata()+1);
		fr=c;
		cnt++;	 
	}
}
template<typename T>
void Forward_list<T>::pop_front()
{
	  node<T>* a=fr;
        if(fr==NULL)
                return;
       if(a->getnext()==NULL)
        {
                fr=NULL;
               // rr=NULL;
         }
         else{    
       
        //a->setpnull();
        fr=a->getnext();
	//fr->setpnull();
	}
        delete a;
        //ptr->setdata(ptr->getdata()-1);
	cnt--;
}
 
template<typename T>
int Forward_list<T>::empty()
{
	if(cnt==0)
		return 1;
	else
		return 0;
}

template<typename T>
int Forward_list<T>::size()
{
	int cnt=0;
	node<T>*a=fr;
	while(a!=NULL)
	{
		cnt++;
		a=a->getnext();
	}
	return cnt;
}
template<typename T>
void Forward_list<T>::erase(Iterator<T> pos)
{
	if(pos==fr)
		pop_front();
	else
	{
		node<T>*a=pos.getNode();
		node<T>*b=a->getnext();
		node<T>*p=fr;
		while(p->getnext()!=NULL)
		{
			p=p->getnext();
		}
		node<T>*c=p;
		//node<T>*c=a->getprev();
		c->setnext(b);
		//b->setprev(c);
		delete a;
		cnt--;
	}
}
template<typename T>
T Forward_list<T>::front()
{
	//node<T>*a=ptr->getprev();
	//return a->getdata();
	return fr->getdata();
}
template<typename T>
void Forward_list<T>::insert(Iterator<T>pos,T val)
{
	if(pos==NULL)
		return;
	if(pos==begin())
	{
		push_front(val);
		return;
	}
	node<T>*a=new node<T>(val);
	node<T>*tmp=pos.getNode();
	//node<T>*pre=tmp->getprev();
	node<T>*p=fr;
		while(p->getnext()!=NULL)
		{
			p=p->getnext();
		}
		node<T>*pre=p;
	//a->setprev(pre);
	a->setnext(tmp);
	pre->setnext(a);	
	//tmp->setprev(a);
	cnt++;
}
