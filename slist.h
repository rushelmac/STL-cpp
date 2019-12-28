#include<iostream>
#include<cstdlib>
#include <bits/stdc++.h>
template<typename T>
class node
{
	T data;
	node<T> *next;
	node<T> *prev;
	public:
		node()
		{
			data=0;
			next=NULL;
			prev=NULL;
		}
		node(T d)
		{
			data=d;
			prev=NULL;
			next=NULL;
		}
		node(T d,node<T>*t1,node<T>*t2)
		{
			data=d;
			next=t2;
			prev=t1;
		}
		~node(){}
		void setdata(T d)
		{
			data=d;
		}
		T getdata(){return data;}
		node<T>*getnext(){return next;}
		node<T>*getprev(){return prev;}
		void setnext(node<T>*t2){next=t2;}
		void setnull(){next=NULL;}
		void setprev(node<T>*t1){prev=t1;}
		void setpnull(){prev=NULL;}
};
template<typename T>
class iterator
{
	private:
	node<T>*itr;
	public:
		iterator(){itr=NULL;}
		iterator(node<T>* par){ itr=par;}
		T operator*(){return itr->getdata();}
		 iterator operator++(int)
		{
			itr=itr->getnext();
			return *this;
		}
		iterator operator++()
		{
			itr=itr->getnext();
			return *this;
		}
		iterator operator--()
		{
			itr=itr->getprev();
			return *this;
		}
		
		bool operator==(const iterator&k)
		{
			return itr==k.itr;
		}
		bool operator!=(const iterator&k)
		{
			return itr!=k.itr;
		}
		node<T>* getnode()
		{
			return itr;
		}
};
template<typename T>
/*
void addAtBeg(DataTypeOfNode data){
        LinearList<DataTypeOfNode>::addAtBeg(data) ; 
    }

    DataTypeOfNode removeFromFront(){
        return LinearList<DataTypeOfNode>::removeFromFront() ; 
    }*/				
class list:public iterator<T>
{
	private:
		int cnt;
	public:
	list():node<T>(){}
	~list<T>(){}
	void push_back(T);
	void push_front(T);
	void pop_front();
	 void pop_back();
	void display();
	void setdata(T d){iterator<T>::setdata();}
	void setnull(){iterator<T>::setnull();}
	void setpnull(){iterator<T>::setpnull();}
	void setnext(node<T>*t2){iterator<T>::setnext();}
	void setprev(node<T>*t2){iterator<T>::setprev();}
	T getdata(){return iterator<T>::getdata();}
	node<T>*getprev(){return iterator<T>::getprev();}
	iterator<T> begin(){return getprev();}
	node<T>*getnext(){return iterator<T>::getnext();}
	iterator<T> end(){return getnext();}
	iterator<T> rbegin(){return getnext();}
	iterator<T> rend(){return getprev();}
	T front();
	T back();
	int empty();
	void assign(node<T>*,node<T>*);
	void assign (int,T);
	int size();
	void erase(iterator<T>);
	void insert(iterator<T>,T);

};
template<typename T>
void list<T>::push_back(T d)
{
	node<T>* a=new node<T>(d);
	if(getnext()==NULL)
	{
		setprev(a);
	}
	else
	{
		node<T>* b=getnext();
		b->setnext(a);
		a->setprev(b);
	}
	setdata(getdata()+1);
	setnext(a);
}
template<typename T>
void list<T>::push_front(T d)
{
	node<T>* a=new node<T>(d);
	if(getprev()==NULL)
	{
		setnext(a);
	}
	else
	{
		node<T>*b=getprev();
		a->setnext(b);
		b->setprev(a);
	}
	setdata(getdata()+1);
	setprev(a);
}
//To assign elements to a list<T>.
template<typename T>
void list<T>::assign (int n,T val)
{
	setnext(NULL);
	setprev(NULL); 
	//node* a=new node(val);
	//setprev(a);
	for(int i=1;i<=n;i++)
	{
		node<T>* c=new node<T>(val);
		if(getnext()==NULL)
		{
			setprev(c);
		}
		else
		{
			node<T>* b=getnext();
			b->setnext(c);
			c->setprev(b);
		}
		setdata(getdata()+1);
		setnext(c);	 
	}
}
//To copy elements from an existing list<T> to a new list<T>.
template<typename T>
void list<T>::assign(node<T>* a,node<T>* b)
{
      
	setnext(NULL);
	setprev(NULL); 
	//c=begin();d=end();
	for(;a!=b->getnext();a=a->getnext())
	{
		node<T>* c=new node<T>(a->getdata());
		if(getnext()==NULL)
		{
			setprev(c);
			setnext(c);
		}
		else
		{
			node<T>* b=getnext();
			b->setnext(c);
			c->setprev(b);
		}
		setdata(getdata()+1);
		setnext(c);	  
	}
}	 	
template<typename T>	  
void list<T>::display()
{
	node<T> *a=getprev();
	std::cout<<"\n List:";
	if(a==NULL)
	{
		std::cout<<"\n Empty list<T>.";
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
template<typename T>
void list<T>::pop_front()
{
        if(getdata()==0)
                return;
         node<T>* a=getprev();
        if(a->getnext()==NULL)
        {
                setnull();
                setpnull();
         }
         else{    
       
        a->setpnull();
        setprev(a->getnext());
        delete a;
        setdata(getdata()-1);
        }
}
template<typename T>
void list<T>::pop_back()
{
        if(getdata()==0)
                return;
         if(getdata()==1)
         {node<T>* a=getnext();
                delete a;
                setnull();
                setpnull();
                setdata(0);
                return;
         }
         node<T>* a=getnext();
         node<T>*b=a->getprev();
         b->setnull();
        setnext(b);
        setdata(getdata()-1);
        delete a;
}

template<typename T>
int list<T>::size()
{
	int cnt=0;
	node<T>*a=getprev();
	while(a!=NULL)
	{
		cnt++;
		a=a->getnext();
	}
	return cnt;
}
template<typename T>
//To erase single element at given pos	
void list<T>::erase(iterator<T> pos)
{
	if(pos==getprev())
		pop_front();
	else if(pos==getnext())
		pop_back();
	else
	{
		node<T>*a=pos.getnode();
		node<T>*b=a->getnext();
		node<T>*c=a->getprev();
		c->setnext(b);
		b->setprev(c);
		delete a;
		cnt--;
	}
}
template<typename T>
T list<T>::front()
{
	node<T>*a=getprev();
	return a->getdata();
}

template<typename T>
T list<T>::back()
{
	node<T>*a=getnext();
	return a->getdata();
}
 
template<typename T>
int list<T>::empty()
{
	if(getdata()==0)
		return 1;
	else
		return 0;
}																						
template<typename T>
void list<T>::insert(iterator<T>pos,T val)
{
	node<T>*a=new node<T>(val);
	node<T>*tmp=pos.getnode();
	node<T>*pre=tmp->getprev();
	a->setprev(pre);
	a->setnext(tmp);
	pre->setnext(a);	
	tmp->setprev(a);
	cnt++;
}
//Removes all the elements from the list, which are equal to given element.
template<typename T>
void list<T>::remove(T val)
{
	node<T>*a=getprev();
	while(a!=NULL)
	{
		if(a->getdata()==val)
			erase(iterator<T>(a));
		a=a->next;
	}
}
	 
