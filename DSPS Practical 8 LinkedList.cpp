/*  A Library system need to manage the collection of books (datafields such as book title, author, ISBN NO, availability status 
	and other relevant information) maintain the information about each book support operation like adding, removing and searching 
	for books and provide 	the efficient access to library resources. Use the concept of linkedlist for implementation of Library 
	Management System.*/
	
#include<iostream>
using namespace std; 	
struct Node
{
	int data; 
	Node* next; 
};
class Library
{
	Node* head=NULL; 
	public : 
		void InsertAtBegining(int val)
		{
			Node *newnode= new Node();
			newnode->data= val;
			newnode->next = head;
			head = newnode; 
		}
		void InsertAtEnd(int val)
		{
			Node *temp = head; 
			Node *newnode = new Node(); 
			newnode-> data = val; 
			newnode-> next = NULL; 
			while(temp->next=NULL)
			{
				temp= temp->next; 
			}
			temp-> next = newnode;
		}
		
		void Display()
		{
			if(!head)
			{
				cout<<"List is Empty"; 
				return; 
			}
			else 
			{
				Node *temp = head; 
				cout<<endl; 
				while(temp->next !=NULL)
				{
					cout<<temp->data<<"->"; 
					temp = temp->next; 
				}
				cout<<"NULL"; 
			}
		}
		void Search()
		{
			if(!head)
			{
				cout<<"List is Empty"; 
				return; 
			}
			int d; 
			cout<<"\nEnter the data You want to Search :"<<endl; 
			cin>>d; 
			Node *temp = head; 
			cout<<endl; 
			while(temp)
			{
				if(temp->data==d)
				{
					cout<<"\nData is found : "<<temp->data; 
					break;
				}
				temp=temp->next; 
			}
		}
			
		void InsertAfter(int val)
		{
			Node *newnode = new Node(); 
			newnode ->data = val; 
			int pos; 
			cout<<"\nEnter the Position of node want to insert at  :"<<endl; 
			cin>>pos; 
			Node *temp = head; 
			cout<<endl; 
			while(temp)
			{
				if(temp->data==pos)
				{
					newnode->next = temp -> next; 
					temp->next = newnode; 
					//cout<<"\nData is found : "<<temp->data; 
					break;
				}
				temp=temp->next; 
			}
		}
};
int main()
{
	Library l; 
	l.InsertAtBegining(10);
	l.InsertAtBegining(20);
	l.InsertAtBegining(30);
	l.InsertAtEnd(40);
	l.InsertAfter(60);
	l.Display(); 
	l.Search(); 
	return 0; 
}
