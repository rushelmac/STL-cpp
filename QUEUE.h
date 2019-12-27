#include<iostream>
#include"NODE.h"
using namespace std;
template<typename T>
class que
{
	node<T>* fr;
	node<T>* rr;
	public:
		que(){
			fr=NULL;
			rr=NULL;
		}
		~que(){
			node<T>* a=fr,*b;
			b=a->getnext();
			while(a!=NULL)
			{
				delete a;
				a=b;
				b=a->getnext();
			}
		}
		void insert(T d)
		{
			node<T>* a=new node<T>(d);
			if(fr=NULL)
			{
				fr=a;
			}
			else
			{
				rr->getnext()=a;
			}
			rr=a;
		}
		void remque()
		{
			node<T>* a=fr;
			if(fr==NULL)
				return;
			else
			{
				if(fr==rr)
					fr=rr=NULL;
				else
					fr=fr->getnext();
				delete a;
			}
		}
		void display()
		{
			node<T>* a=fr;
			if(fr==NULL)
				return;
			else
			{
				while(a->getdata()!=NULL)
				{
					cout<<" "<<a->getdata();
					a=a->getnext();
				}
			}
		}
};

