#include<iostream>
#include<cstdlib>
using namespace std;
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
		Iterator operator--()
		{
			itr=itr->getprev();
			return *this;
		}
		
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
class List:public Iterator<T>
{
	private:
		int cnt;
		node<T>* fr;
		node<T>* rr;
	public:
	List(){
		fr=NULL,rr=NULL;
		cnt=0;
	}
	~List(){}
	void push_back(T);
	void push_front(T);
	void assign (int,T);
	void pop_front();
	void pop_back();
	void assign(Iterator<T>,Iterator<T>);
	Iterator<T>begin(){return fr;}
	Iterator<T> end(){return rr->getnext();
	Iterator<T> rbegin(){return rr->getnext();}
	Iterator<T> rend(){return fr;}
	T front();
	T back();
	int empty();
	int size();
	void erase(Iterator<T>);
	void insert(Iterator<T>,T);
	void remove(T val);
	void display();
	void Sort();

};
template<typename T>
void List<T>::push_back(T d)
{
	node<T>* a=new node<T>(d);
	if(fr==NULL)
	{
		fr=a;
	}
	else
	{
		//node<T>* b=ptr->getnext();	
		//b->setnext(a);
		//a->setprev(b);
		rr->setnext(a);
		a->setprev(rr);
	}
	//ptr->setdata(ptr->getdata()+1);
	rr=a;
	cnt++;
	return;
}
template<typename T>
void List<T>::push_front(T d)
{
	node<T>* a=new node<T>(d);
	
	if(rr==NULL)
	{
		rr=a;
	}
	else
	{
		//node<T>* b=ptr->getprev();
		//a->setnext(b);
		//b->setprev(a);
		a->setnext(fr);
		fr->setprev(a);
	}
	//ptr->setdata(ptr->getdata()+1);
	fr=a;
	cnt++;
	return;
}
//To assign elements to a List<T>.
template<typename T>
void List<T>::assign (int n,T val)
{
	fr=rr=NULL;
	//node* a=new node(val);
	//setprev(a);
	for(int i=1;i<=n;i++)
	{
		node<T>* c=new node<T>(val);
		if(rr==NULL)
		{
			fr=c;
		}
		else
		{
			//node<T>* b=ptr->getnext();
			rr->setnext(c);
			c->setprev(rr);
		}
		//ptr->setdata(ptr->getdata()+1);
		rr=c;
		cnt++;	 
	}
}
//To copy elements from an existing List<T> to a new List<T>.
template<typename T>
void List<T>::assign(Iterator<T> a,Iterator<T> b)
{
	//fr=rr=NULL;
      //node<T>* tmp1=a.getNode();
//	node<T>* tmp2=b.getNode();
	fr=a.getNode();
	rr=b.getNode();
	for(int i=1;rr->getnext()!=NULL;i++)
	{
		cnt++;
	}
}	 	
template<typename T>	  
void List<T>::display()
{
	node<T> *a=fr;
	std::cout<<"\n List:";
	if(a==NULL)
	{
		std::cout<<"\n Empty List<T>.";
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
void List<T>::pop_front()
{
	  node<T>* a=fr;
        if(fr==NULL)
                return;
      /*  if(a->getnext()==NULL)
        {
                fr=NULL;
                rr=NULL;
         }*/
         else{    
       
        //a->setpnull();
        fr=a->getnext();
	fr->setpnull();
	}
        delete a;
        //ptr->setdata(ptr->getdata()-1);
	cnt--;
}
template<typename T>
void List<T>::pop_back()
{
        
	node<T>* a=rr;
	if(rr==NULL)
                return;
        if(a->getprev()==NULL)
        {
                fr=NULL;
                rr=NULL;
         }
         else{    
       
       // a->setprev(NULL);
        rr=a->getprev();
	rr->setnull();
	}
        delete a;
        //ptr->setdata(ptr->getdata()-1);
	cnt--;
        
}

template<typename T>
int List<T>::size()
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
//To erase single element at given pos	
void List<T>::erase(Iterator<T> pos)
{
	if(pos==fr)
		pop_front();
	else if(pos==rr)
		pop_back();
	else
	{
		node<T>*a=pos.getNode();
		node<T>*b=a->getnext();
		node<T>*c=a->getprev();
		c->setnext(b);
		b->setprev(c);
		delete a;
		cnt--;
	}
}
template<typename T>
T List<T>::front()
{
	//node<T>*a=ptr->getprev();
	//return a->getdata();
	return fr->getdata();
}

template<typename T>
T List<T>::back()
{
	//node<T>*a=ptr->getnext();
	return rr->getdata();
}
 
template<typename T>
int List<T>::empty()
{
	if(cnt==0)
		return 1;
	else
		return 0;
}																						
template<typename T>
void List<T>::insert(Iterator<T>pos,T val)
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
	node<T>*pre=tmp->getprev();
	a->setprev(pre);
	a->setnext(tmp);
	pre->setnext(a);	
	tmp->setprev(a);
	cnt++;
}
//Removes all the elements from the List, which are equal to given element.
template<typename T>
void List<T>::remove(T val)
{
	node<T>*a=fr;
	while(a!=NULL)
	{
		if(a->getdata()==val)
			erase(Iterator<T>(a));
		a=a->getnext();
	}
}
template<typename T>
void List<T>::Sort()
{
	node<T>* temp = fr; 
    while (temp) { 
        node<T>* min = temp; 
        node<T>* r = temp->getnext();
        while (r) { 
            if (min->getdata() > r->getdata()) 
                min = r; 
  
            r = r->getnext(); 
        } 
  
        // Swap Data 
        T x = temp->getdata(); 
        temp->setdata(min->getdata()); 
        min->setdata(x); 
        temp = temp->getnext(); 
    } 
} 

