//#include<iostream>
//using namespace std;
template<typename T>
class node
{
		T data;
		node * next;
	public:
		node() {next=NULL;}
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
		
		void setdata(T d){data=d;}
		
		T getdata(){return data;}
		
		node* getnext(){return next;}
		
		void setnext(node*t){next=t;}
		
		void setnull(){next=NULL;}
};
