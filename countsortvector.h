
  #include"vector.h"
void countSort(vector<int>& arr) 
{ 
    int max =arr[0];
	int min =arr[0];
	 for (int i = 0; i < arr.size(); i++) 
        {
			 if(max<arr[i])
			 {
			 	max=arr[i];
			 }
			 if(min>arr[i])
			 {
			 	min=arr[i];
			 }
  		
		  }
		//cout<<"max"<<max<<"\nmin"<<min<<endl;
		cout<<"checkpoint 1 clear";
	int n=arr.size();
    int range = max - min + 1; 
		cout<<"checkpoint 2 clear";
    vector<int> count, output; 
    	cout<<"checkpoint 3 clear";
    	for(int i=0;i<range;i++)
  		{
  			count.push_back(0);
		}
			for(int i=0;i<n;i++)
  		{
  			output.push_back(0);
		}   
    
    for (int i = 0; i < arr.size(); i++) 
        count[arr[i] - min]++; 
  
    for (int i = 1; i < range; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = arr.size() - 1; i >= 0; i--) { 
        output[count[arr[i] - min] - 1] = arr[i]; 
        count[arr[i] - min]--; 
    } 
  
    for (int i = 0; i < arr.size(); i++) 
        arr[i] = output[i]; 
} 
  
void printArray(vector<int>& arr) 
{ 
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  

