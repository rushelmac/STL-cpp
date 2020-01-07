#include"vector.h"
template<typename T>
class stack
{
	int top;
	vector<T> arr;
	public:
		stack();
		~stack(){
		}
		void push(T d);
		T pop();
		T topval();
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
