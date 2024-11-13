#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isPalindrome(string str)
{
	stack<char>s; 
	int length = str.length();
	for( int i=0;i<length;i++)
	{	
		s.push(str[i]);
	}
	for(int i=0;i<length;i++)
	{	
		if(s.top()!=str[i])
		{	
			return false; 
		}
		s.pop();
	}
	return true; 
}
int main()
{	
	string str; 
	cout<<"Enter a String :";
	cin>>str; 
	if(isPalindrome(str))
	{
		cout<<"String is Palindrome : "<<str<<endl; 
	}
	else 
	{	
		cout<<"String is not a Palindrome : "<<str<<endl; 
	}
return 0; 
}


