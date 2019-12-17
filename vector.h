#include<iostream>
using namespace std;


template<typename T>
class vector
{
	T* arr;
	int syz,capa;
	public :
		typedef T* Iterator;
		vector<T>()
		{
			arr=new T;
		}
		~vector<T>()
		{
			delete arr;
		}
		Iterator begin();
		Iterator end();
		int size();
		int capacity();
		void resize(int);
		bool empty();
		void shrink_to_fit();
		void reserve(int);
		T* back();
		T* front();
		void assign(int,T*);
		void assign(T*,int);
		void push_back(T);
		void pop_back();
		T* insert(int,T);
		T* insert(int,int,T);
		void erase(int);
		void swap(T*);
		void clear();
		//T* emplace();
};
template<typename T>
typename vector<T>::Iterator vector<T>::begin()
{
	return arr;
}

template<typename T>
typename vector<T>::Iterator vector<T>::end()
{
	return arr+syz;
}

template<typename T>
int vector<T>::size()
{
	return syz;
}

template<typename T>
int vector<T>::capacity()
{
	return capa;
}

template<typename T>
bool vector<T>::empty()
{
	return (syz==0);
}

template<typename T>
void vector<T>::shrink_to_fit()
{
	T*  arr2=new T[syz];
	T* ar;
	for(int i=0;i<syz;i++)
	{
		arr2[i]=arr[i];
	}
	ar=arr;
	arr=arr2;
	delete ar;
}

template<typename T>
void vector<T>::resize(int n)
{
	static T* arr2,ar;
	arr2=new T[n];
	for(int i=0;i<syz;i++)
	{
		arr2[i]=arr[i];
	}
	ar=arr;
	arr=arr2;
	delete ar;
}

template<typename T>
void vector<T>::reserve(int n)
{
	if(n<syz)
		return;
	T* arr2=new T[n],*ar;
	for(int i=0;i<syz;i++)
	{
		arr2[i]=arr[i];
	}
	ar=arr;
	arr=arr2;
	delete ar;
}

template<typename T>
T* vector<T>::back()
{
	return arr+syz;
}

template<typename T>
void vector<T>::assign(int sz,T* vl)
{
	if(size<sz)
	{
		T* arr2=new T[sz],*ar;
		for(int i=0;i<size;i++)
		{
			&arr[i]=vl;
		}
		ar=arr;
		arr=arr2;
		delete ar;
	}
	else
	{
		for(int i=0;i<sz;i++)
			arr[i]=vl;
	}
}




template<typename T>
void vector<T>::push_back(T val)
{
	if(syz==capa)
	{
		int i;
		capa*=2;
		T* arr2=new T[capa],*ar;
		for(i=0;i<syz;i++)
		{	
			arr2[i]=arr[i];
		}
		arr2[i]=val;
		ar=arr;
		arr=arr2;
		delete ar;
		syz++;
	}
	else
	{
		arr[syz]=val;
		syz++;
	}
}

template<typename T>
void vector<T>::pop_back()
{
	syz--;
}

template<typename T>
T* vector<T>::insert(int pos,T val)
{
	arr[pos]=val;
	return &arr[pos];
}

template<typename T>
T* vector<T>::insert(int pos,int size,T val)
{
	for(int i=0,j=pos-1;i<size;i++,j++)
	{
		arr[j]=val;	
	}
	return &arr[pos];	
}

template<typename T>
void vector<T>::erase(int pos)
{
	int i=0,j=0;
	T* arr2=new T[capa];
	while(i<syz)
	{
		if(i!=pos-1)
		{
			arr2[i]=arr[j];
			i++;
		}
		j++;
	}
}

template<typename T>
void vector<T>::swap(T*arr2)
{
	T tmp;
	for(int i=0;i<syz;i++)
	{
		tmp=arr2[i];
		arr2[i]=arr[i];
		arr[i]=tmp;
	}
}

template<typename T>
void vector<T>::clear()
{
	delete arr;
}
/*int main()
{
	vector v;
}*/
