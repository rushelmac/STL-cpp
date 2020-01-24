#include"vector.h"
template<typename T>
class stack
{
	vector<T> arr;
	int top;
	public:
		stack();
		~stack(){
		}
		void push(T d);
		T pop();
		T topval();
		bool empty();
		int size();
		void insert(int,T);
		int search(T);
};
template<typename T>
stack<T>::stack()
{
	top=-1;
}
template<typename T>
void stack<T>::push(T d)
{
	arr.push_back(d);
	top++;	
}
template<typename T>
T stack<T>::pop()
{
	if(top==-1)
		return -1;
	top--;
	return arr.pop_back();
}
template<typename T>
T stack<T>::topval()
{
	if(top==-1)
		return;
	return arr[top];
}

template<typename T>
bool stack<T>::empty()
{
	return (top==-1);
}

template<typename T>
int stack<T>::size()
{
	return (top+1);
}
template<typename T>
void stack<T>::insert(int pos,T val)
{
	if(pos>top)
		return;
	arr.insert((top-pos),val);
}
template<typename T>
int stack<T>::search(T val)
{
	arr.search(val);
}
