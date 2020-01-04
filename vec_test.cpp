#include"vector.h"
//	Iterator begin();
//		Iterator end();
//		int size();
//	check	int capacity();
//	updated	void resize(int);
//	checked	bool empty();
//	updated	void shrink_to_fit();
//	updated	void reserve(int);
//	updated	T* back();
//	updated	T* front();
//	updated	void assign(int,T*);
//	check	void push_back(T);
//	updated	void pop_back();
//	updated	T* insert(int,T);
//	updated	T* insert(int,int,T);
//	updated	void erase(int);
//	updated	void swap(T*);
//	updated	void clear();
//		//T* emplace();
//		T* operator ++();
//		void display();
//		T& operator[](int);

int main()
{
	vector<int> vec,vec2;
	
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(34);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(34);
	
	vec2.push_back(4);
	vec2.push_back(5);
	vec2.push_back(74);
	vec2.push_back(1);
	vec2.push_back(0);
	vec2.push_back(4);	
	//vector<int>::Iterator itr;
	//itr=vec.begin();
//	cout<<vec.size();
//	for(int i=0;i<vec.size();i++)
//		cout<<vec[i]<<endl;

	vec.display();
	vec2.display();
	cout<<"\nSize="<<vec.size()<<" Capacity="<<vec.capacity();
	
	vec.swap(vec2);
	
	vec.display();
	vec2.display();
	cout<<"\nSize="<<vec.size()<<" Capacity="<<vec.capacity();
}
