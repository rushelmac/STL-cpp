#include<stdio.h>
using namespace std;

static int syz,capa;
template<class T>
class vector
{
	T* arr;
	public :
		vector<T>()
		{
			arr=new T;
		}
		~vector<T>()
		{
			delete arr;
		}
		T* begin();
		T* end();
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
template<class T>
T* vector<T>::begin()
{
	return arr;
}

template<class T>
T* vector<T>::end()
{
	return arr+syz;
}

template<class T>
int vector<T>::size()
{
	return syz;
}

template<class T>
int vector<T>::capacity()
{
	return capa;
}

template<class T>
bool vector<T>::empty()
{
	return (syz==0);
}

template<class T>
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

template<class T>
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

template<class T>
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

template<class T>
T* vector<T>::back()
{
	return arr+syz;
}

template<class T>
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




template<class T>
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

template<class T>
void vector<T>::pop_back()
{
	syz--;
}

template<class T>
T* vector<T>::insert(int pos,T val)
{
	arr[pos]=val;
	return &arr[pos];
}

template<class T>
T* vector<T>::insert(int pos,int size,T val)
{
	for(int i=0,j=pos-1;i<size;i++,j++)
	{
		arr[j]=val;	
	}
	return &arr[pos];	
}

template<class T>
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

template<class T>
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

template<class T>
void vector<T>::clear()
{
	delete arr;
}
/*int main()
{
	vector v;
}*/
