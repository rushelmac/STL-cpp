#include<iostream>
#include "Forward_list.h"
using namespace std;
int main()
{
	Forward_list<int>fl1;
	fl1.push_front(3);
	fl1.push_front(4);
	fl1.push_front(5);
	//fl1.assign(4,5);
	//fl1.assign(3,70);
	fl1.display();
	auto it=fl1.begin();
	//fl1.erase(it);
	fl1.insert(it,87);
	fl1.display();
	//fl1.pop_front();
	int size=fl1.size();
	cout<<"\n size of list:"<<size<<endl;
	//fl1.display();
	return 0;
}
