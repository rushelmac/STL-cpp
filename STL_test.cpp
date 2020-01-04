#include<iostream>
#include"vector.h"
#include"Algorithm.h"
//#include"bits/stdc++.h"
using namespace std;

int main()
{
	char *test;
	vector<char> arr;
	arr.push_back('a');
	arr.push_back('b');
	arr.push_back('c');
	int i=0;
	bool t=1;
	//distance(arr.begin(),arr.end());
	//arr.display();
//	while(t)
//	{
//		i=0;
//		while(i<arr.size())
//		{
//			cout<<arr[i];
//			i++;
//		}
//		cout<<endl;
//		t=next_permutation(arr.begin(),arr.end());
//	}
	if(binary_search(arr.begin(),arr.end(),'b'))
	{
		cout<<"\nyes";
	}
	return 0;
}

