# STL-cpp  (GTL)
Collection of stl header files in cpp.

## About STL : 
    The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a prerequisite for working with STL.

## About the project : 
    The project done by team members is mind blowing. 

## The Header Files : 
    STL contains 4 types of header files 
1.Iterators
2.Containers
3.Algorithms
4.Functors
	In the project, we have covered the first 3.

## Containers : 
1. vector.h :
	Functions of vector :
		
		1)T* begin() : 
		This functions returns a pointer to the begining of array.[O(1)]
		
		2)T* end()   : 
		This functions returns a pointer pointing to imaginary position after the last element.[O(1)]
		
		3)int size() : 
		This functions returns the size of vector array in terms of number of elements.[O(1)]
		
		4)int capacity(): 
		Returns the size of the storage space currently allocated to the vector expressed as number of elements [O(1)]
		
		5)void resize(int): 
		Resizes the container so that it contains ‘n’ elements.It will do nothing if 'size > n'.
		
		6)bool empty() : 
		Returns whether the container is empty.
		
		7)void shrink_to_fit() : 
		Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
		
		8)void reserve(int): 
		Requests that the vector capacity be at least enough to contain n elements.
		
		9)T* front() :
		Returns a reference to the first element in the vector[O(1)]
		
		10)T* back() :
		Returns a reference to the last element in the vector[O(1)]
		
		11)void assign(int, T) : 
		It assigns new value to the vector elements by replacing old ones.[O(n)]
		
		12)void push_back() : 
		It push the elements into a vector from the back.[O(1)]
		
		13)T pop_back() : 
		It is used to pop or remove elements from a vector from the back.[O(1)]
		
		14)T* insert(int, T) : 
		It inserts new element before the element at the specified position.[O(1)]
		
		15)T* insert(int, int, T) : 
		Inserts new element for the given range in the vector array.[O(range)]
		
		16)void erase(int) : 
		It is used to remove elements from a container from the specified position or range.[O(1)]
		
		17)void swap(vector<T>&) :
		It is used to swap the contents of one vector with another vector of same type. Sizes may differ.[O(n)]
		
		18)void clear() : 
		It is used to remove all the elements of the vector container.[O(1)]
		
		19)*void display() : 
		This function is used to display the contents of vector.
		
		20)*int search(T) : 
		Performs binary search on the vector.[O(log(n))]
		
2. stack.h :
	Functions of stack :
		
		1)bool empty() : 
		Returns whether the stack is empty – Time Complexity : O(1)
		
		2)int size() : 
		Returns the size of the stack – Time Complexity : O(1)
		
		3)T topval() : 
		Returns a reference to the top most element of the stack – Time Complexity : O(1)
		
		4)void push(T) : 
		Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
		
		5)T pop() : 
		Deletes the top most element of the stack – Time Complexity : O(1)
		
		6)*void insert(int, T) : 
		This function inserts an element at certain position from the top.(Overriding the general ADT of stack)
		
		7)*int search(T) : 
		Performs binary search on stack. 

3. queue.h : 
	Functions of queue :
		
		1)empty() : 
		Returns whether the queue is empty.[O(1)]
		
		2)size() : 
		Returns the size of the queue.
		
		3)swap() : 
		Exchange the contents of two queues but the queues must be of same type, although sizes may 
		differ.[O(n)]
		
		4)emplace() : 
		Insert a new element into the queue container, the new element is added to the end of the queue.
		
		5)T* front() : 
		front() function returns a reference to the first element of the queue.[O(1)]
		
		6)T* back() : 
		back() function returns a reference to the last element of the queue.[O(1)]
		
		7)void push(g) : 
		This function adds the element ‘g’ at the end of the queue.[O(1)]
		
		8)T pop() : 
		This function deletes the first element of the queue.[O(1)]

4. List in STL:

	Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, list has slow traversal, but 		once a position has been found, insertion and deletion are quick.

		1)front:
		The list::front() is a built-in function in C++ STL which is used to return a reference to the first element in a list container. Unlike the list::begin() function, this function returns a direct reference to the first element in the list 		container.Return Value: This function returns a direct reference to the first element in the list container.

		2)Back:
		The list::back() function in C++ STL returns a direct reference to the last element in the list container. This function is different from the list::end() function as the end() function returns only the iterator to the last element.

		3)Push_front(): 
		The list::push_front() is a built-in function in C++ STL which is used to insert an element at the front of a list container just before the current top element. This function also increases the size of the container by 1.

		4)push_back():
		The list:push_back() function in C++ STL is used to add a new element to an existing list container. It takes the element to be added as a parameter and adds it to the list container.

		5)pop_front:
		The list::pop_front() is a built-in function in C++ STL which is used to remove an element from the front of a list container. This function thus decreases the size of the container by 1 as it deletes the element from the front of a list.

		6)begin():
		function is used to return an iterator pointing to the first element of the list container. It is different from the front() function because the front function returns a reference to the first element of the container but begin() function returns a bidirectional iterator to the first element of the container.(Time complexity=O(1))

		7)end():
		 function is used to return an iterator pointing to the last element of the list container. It is different from the back() function because the back() function returns a reference to the last element of the container but end() function returns a bidirectional iterator to the last element of the container. (Time complexity=O(1))

		8)The list::insert() is used to insert the elements at any position of list.his function returns an iterator that points to the first of the newly inserted elements.

		9)unique:
		list::unique() is an inbulit function in C++ STL which removes all duplicate consecutive elements from the list.

		10)sort() function is used to sort the elements of the container by changing their positions.(O(nlogn))

		11)The list::erase() is a built-in function in C++ STL which is used to delete elements from a list container.This function returns an iterator pointing to the element in the list container which followed the last element erased from the list container.

