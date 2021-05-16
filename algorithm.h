#include<iostream>
//sort(first_itr,last_itr)   //checked
//reverse(first_itr,last_itr)  //checked
//*max_element(first_itr,last_itr)  //checked
//*max_element(first_itr,last_itr)  //checked
//accumulate(first_iterator, last_iterator, initial value of sum) //checked
//count(first_iterator, last_iterator,x) //checkeed
//find(first_iterator, last_iterator, x) //checked
template<typename T>
void swap(T *i,T *j)
{
	T tmp=*i;
	*i=*j;
	*j=tmp;
}
template<typename T>
T* partition(T* i,T* j)
{
	T* start=i;
		do{
			do{
				++i;;
			}while(*i<*start);
			do{
				--j;
			}while(*j>*start);
			if(i<j)
				swap(i,j);
		}while(i<j);
		swap(j,start);
		return j;		
}
template<typename T>
void qsort(T* i,T* j)
{
	T* k=NULL;
	if(i<j)
	{
		if(*i>*j)
			swap(i,j);
		k=partition(i,j);
		qsort(i,k-1);
		qsort(k+1,j);
	}
}
template<typename T>
void sort(T* first_itr,T* last_itr)
{
	T* i=first_itr,*j=last_itr-1;
	qsort(i,j);
}
template<typename T>
void reverse(T* first_itr,T* last_itr)
{
	T* i=first_itr,*j=last_itr-1;
	for(;i<j;i++,j--)
	{
		swap(i,j);
	}
}
template<typename T>
T* max_element(T* first_itr,T* last_itr)
{
	T* i=first_itr,*j=last_itr-1;
	T* max=i;
	for(;i<j;i++)
	{
		if(*i<*(i+1))
			max=(i+1);
	}
	return max;
}
template<typename T>
T* min_element(T* first_itr,T* last_itr)
{
	T* i=first_itr,*j=last_itr-1;
	T* min=i;
	for(;i<j;i++)
	{
		if(*i>*(i+1))
			min=(i+1);
	}
	return min;
}
template<typename T>
T accumulate(T* first_itr,T* last_itr,T ini_sum)
{
	T* i=first_itr,*j=last_itr-1;
	T sum=ini_sum;
	for(;i<=j;i++)
	{
		sum+=*i;
	}
	return sum;
}	
template<typename T>	
int count(T* first_itr,T* last_itr,T x)
{
	 T* i=first_itr,*j=last_itr-1;
	int cnt=0;
	for(;i<=j;i++)
	{
		if(*i==x)
			cnt++;
	}
	return cnt;
}
template<typename T>	
T* find(T* first_itr,T* last_itr,T x)
{
	 T* i=first_itr,*j=last_itr-1;
	for(;i<=j;i++)
	{
		if(*i==x)
			break;
	}
	return i;
}


//binary_search()            correct for char data type
//lower_bound upper_bound    correct for char data types
//void erase(pos)			 already in vector.h
//next_permutation(first_itr,last_itr)	Algorithm is correct. Testing pending 
//prev_permutation(first_itr,last_itr)	Algorithm is correct. Testing pending
//distance(first_itr,last_itr)			correct for char data types 			

//Checked Correct
template <typename T>
bool binary_search(T* first_itr,T* last_itr,T val)
{
	T* arr=first_itr;
	int r=(last_itr-first_itr)-1,l=0;
	int mid=(r/2);
	cout<<l<<mid<<r<<endl;
	while(l<r)
	{
		int mid=(l+r/2);
		cout<<l<<mid<<r<<endl;
		if(arr[mid]==val)
		{
			cout<<"Found";
			return 1;
		}
		if(arr[mid]>val)
		{
			cout<<"First half";
			r=mid-1;
		}
		if(arr[mid]<val)
		{
			cout<<"Second half";
			l=mid;
		}
	}
	return 0;
}

//checked correct
template <typename T>
T* lower_bound(T* first_itr,T* last_itr,T val)
{
	T* a=first_itr;
	while(a!=last_itr)
	{
		if(*a>=val)
		{
			break;
		}
		a++;
	}
	return a;
}

//checked correct
template <typename T>
T* upper_bound(T* first_itr,T* last_itr,T val)
{
	T* a=first_itr;
	while(a!=last_itr)
	{
		if(*a>val)
		{
			break;
		}
		a++;
	}
	return a;
}


// checked swap function not working
template<typename T>
void swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

template <typename T>
bool next_permutation(T* first_itr,T* last_itr){
	T* arr=first_itr;
	int size=(last_itr-first_itr)/sizeof(T);
	int r=size-1;
	cout<<size<<endl;

	// Find largest index i such that arr[i] > arr[i-1]
	while(--size && arr[r]<=arr[r-1]){
		r-=1;
	}
	if(arr[r]>arr[r-1]){
		for(int j=size-1; j>r; j--){
			if(arr[j]>arr[r-1]){
				swap(arr[j], arr[r-1]);
				reverse(arr[i], arr[size-1]);
				break;
			}
		}
		return true;		
	}	
	// The sequence is in descending order. Make it ascending i.e. first permutation.
	reverse(first_itr, last_itr);
	return false;
}

template <typename T>
bool prev_permutation(T* first_itr,T* last_itr){
	T* arr=first_itr;
	int size=(last_itr-first_itr)/sizeof(T);
	int r=size-1;
	cout<<size<<endl;

	// Find largest index i such that arr[i] < arr[i-1]
	while(r>0 && arr[r]>=arr[r-1]){
		r-=1;
	}
	if(arr[r]<arr[r-1]){	
		for(int j=size-1; j>r; j--){
			if(arr[j]<arr[r-1]){
				swap(arr[j], arr[r-1]);
				reverse(arr[i], arr[size-1]);
				break;
			}
		}
		return true;		
	}	
	// The sequence is in ascending order. Make it descending i.e. last permutation.
	reverse(first_itr, last_itr);
	return false;
}

template <typename T>
void distance(T* first_itr,T* last_itr)
{
	int size=(last_itr-first_itr)/sizeof(T);
	cout<<size;
//	return size;
}


