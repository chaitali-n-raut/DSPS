/*You are given an integer array 'A' of size 'N', sorted in non-decreasing order.You are also given an integer 'target'
your task is to write a function to search for 'target in the array 'A' If it exists return its index in 0-based 
indexing using Linear search in c++*/

/* Linear Search */

#include<iostream>
using namespace std; 
int main()
{
	int a[10], n, i, key, flag=0, count=0; 
	cout<<"Enter Size Of Array :"; 
	cin>>n; 
	cout<<"Enter Elements Of Array :"; 
	for(i=0;i<n;i++)
	{
		cin>>a[i]; 
	}
	cout<<"Enter Key Element To Be Search[target]:";
	cin>>key; 
	for(i=0;i<n;i++)
	{

		if(key==a[i])
		{
			count++;
			flag=1;
			
			break;
		 return count;  

		}
	}
	if(flag==1)
	{
		cout<<"Element Found at Index: "<<i<<endl;
		cout<<"No. of Occurrences in Array :"<<count<<endl; 
	}
	else
	{
		cout<<"Element Not Found"; 
	}
return 0; 
}
