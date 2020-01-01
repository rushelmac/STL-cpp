#include<iostream>
using namespace std;
template<typename T1,typename T2>
struct Pair
{
	T1 first;
	T2 second;
	public:
		Pair()
		{
			first=second=0;
		}
		Pair(T1 data1,T2 data2)
		{
			first=data1;
			second=data2;
		}
		Pair(Pair<T1,T2>&obj)
		{
			first=obj.first;
			second=obj.second;
		}
		Pair operator=(const Pair<T1,T2>&k)
		{
			first=k.first;
			second=k.second;
			return *this;
		}
		bool operator!=(const Pair<T1,T2>&k)
		{
			return(first!=k.first&&second!=k.second);
		}
		bool operator==(const Pair<T1,T2>&k)
		{
			return(first==k.first&&second==k.second);
		}
		bool operator>(const Pair<T1,T2>&k)
		{
			return(first>k.first&&second>k.second);
		}
		bool operator<(const Pair<T1,T2>&k)
		{
			return(first<k.first&&second<k.second);
		}
		Pair swap(Pair<T1,T2>&pr)
		{
			T1 tmp1;
			T2 tmp2;
			tmp1=first;
			first=pr.first;
			pr.first=tmp1;
			tmp2=second;
			second=pr.second;
			pr.second=tmp2;
			return *this;
		}	
		void swap(Pair<T1,T2>&,Pair<T1,T2>&);
		
};
template<typename T1,typename T2>
void swap(Pair<T1,T2>&pr1,Pair<T1,T2>&pr2)
{
	pr1.swap(pr2);
}
