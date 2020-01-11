#include<iostream>
#include"list.h"
using namespace std;

int main() 
{ 
   
    List<int> demoList; 
	//cout<<"\n Assigning 70 3 times:"<<endl;
	//demoList.assign(3,70);
 // List<int> demoList2; 
   demoList.push_back(10); 
    //demoList.push_front(20); 
	demoList.push_back(30); 
	demoList.push_back(40);
	demoList.push_back(90);
	demoList.push_back(60);  
  //  
	// cout << "Initial List: ";
	//demoList.assign(demoList2.begin(),demoList2.end());  
 cout << "Initial List: "; 
//	auto itr=demoList.begin();
	for (auto itr = demoList.begin(); 
         itr != demoList.end(); itr++) { 
        cout << *itr << " "<<endl; }
   
	int size=demoList.size();
	cout<<"\n size of list:"<<size<<endl;
	
  	demoList.pop_front();
	demoList.pop_back();
	cout<<"\n After popping first n last:"<<endl;
	for (int itr:demoList) 
        cout << itr << " "<<endl;
    // List after removing elements 
	demoList.remove(30); 
    cout << "\nList after removing elements: "; 
    for (auto itr = demoList.begin(); 
         itr != demoList.end(); itr++) { 
        cout << *itr << " "<<endl; }
	List<int>::Iterator itr = demoList.begin(); 
	 demoList.insert(itr, 5); 
  
    // Printing the new List 
    cout << "\nThe List after inserting"
         << " 1 element using insert() is : "; 
    for (List<int>::Iterator i = demoList.begin(); 
         i != demoList.end(); 
         i++) 
        cout << *i << " "<<endl; 
  
    cout << endl; 
	demoList.push_back(100);
	 for (auto itr = demoList.begin(); 
         itr != demoList.end(); itr++) { 
        cout << *itr << " "<<endl; }
	int size2=demoList.size();
	cout<<"\n size of list:"<<size2<<endl;
	return 0;
}
																						 

