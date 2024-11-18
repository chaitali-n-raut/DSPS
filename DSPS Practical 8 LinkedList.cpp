/*  A Library system need to manage the collection of books (datafields such as book title, author, ISBN NO, availability status 
	and other relevant information) maintain the information about each book support operation like adding, removing and searching 
	for books and provide 	the efficient access to library resources. Use the concept of linkedlist for implementation of Library 
	Management System.*/
	
//singly linked list 
#include<iostream>
#include<string>
using namespace std ;
class lms
{
	int bid, prize ;
	string title, pub, author ;
	lms *next ;
	public :
		void accept();
		void display() ;
		void search();
		void modify();
		void Delete_first_node() ;
		void Delete_last_node();
} *start, *endd ;
void lms :: accept()
{
	lms *nnode ;
	nnode = new lms ;
	cout<<"Enetr the  book details :" ;
	cout<<"\nEnte the book id :" ;
	cin>>nnode -> bid ;
	cout<<"\nEnte the book title :" ;
	cin>>nnode -> title ;
	cout<<"\nEnte the author name :" ;
	cin>>nnode -> author ;
	cout<<"\nEnte the book publisher name :" ;
	cin>>nnode -> pub ;
	cout<<"\nEnte the book prize :" ;
	cin>>nnode -> prize ;
	nnode->next = NULL ;
	
	if(start == NULL)
	{
		endd = start = nnode ;
	}
	else
	{
		endd -> next = nnode ;
		endd = nnode ;
	}
}
void lms :: display()
{
	lms *temp ;
	temp = start ;
	if(temp == NULL)
	{
		cout<<"\nNO datails found";
	}
	else
	{
		
		while(temp!= NULL)
		{
			cout<<"\n"<<temp->bid<<"\t"<<temp->title<<"\t"<<temp->author<<"\t"<<temp->pub<<"\t"<<temp->prize ;
			temp = temp->next ;
		}
	}
}
void lms :: search()
{
	lms *temp ; 
	int flag = 0 ;
	int id ;
	cout<<"\nEnter the id do you want to search :";
	cin>>id ;
	temp = start ;
	while(temp != NULL)
	{
		if(temp->bid == id)
		{
			flag =1 ;
			cout<<"\nData is found" ;
			cout<<"\n"<<"bid"<<"\t"<<"title"<<"\t"<<"author"<<"\t"<<"pub"<<"\t"<<"prize";
			cout<<"\n"<<temp->bid<<"\t"<<temp->title<<"\t"<<temp->author<<"\t"<<temp->pub<<"\t"<<temp->prize ;
			break ;
		}
		temp = temp->next ;
	}
	if(flag == 0)
	{
		cout<<"\nData is not found" ;
	}
}
void lms :: modify()
{
	lms *temp ;
    int flag = 0 ;
	int id ;
	cout<<"\nEnter the id do you want to modify :";
	cin>>id ;
	temp = start ;
	while(temp != NULL)
	{
		if(temp->bid == id)
		{
			flag = 1 ;
			cout<<"Enetr the book details :" ;
	        cout<<"\nEnte the book id :" ;
			cin>>temp -> bid ;
			cout<<"\nEnte the book title :" ;
			cin>>temp -> title ;
			cout<<"\nEnte the author name:" ;
			cin>>temp -> author ;
			cout<<"\nEnte the book publisher name :" ;
			cin>>temp -> pub ;	
			cout<<"\nEnte the book prize :" ;
			cin>>temp-> prize ;
			break ;
		}
		temp = temp->next ;
	}
	if(flag == 0)
	{
		cout<<"\nData is not found" ;
	}	
}
//Delete first Node
void lms::Delete_first_node()
{
    lms *temp;
    temp=start;
    start=start->next;
    delete temp;
}

//Delete last Node
void lms::Delete_last_node()
{
  lms *temp;
  lms *p;
  temp=start;
  if(temp->next==NULL)
  {
      delete(temp);
  }
  else
  {
      while(temp->next->next!=NULL)
      {
          temp=temp->next;
      }
      p=temp->next;
      delete p;
      temp->next=NULL;
  }
}

int main()
{
	lms c ;
	int ch, choice ;
	do
	{
		cout<<"\n-----------MENU-----------" ;
		cout<<"\n1.Accept" ;
		cout<<"\n2.Display" ;
		cout<<"\n3.Search" ;
		cout<<"\n4.Modify" ;
		cout<<"\n5.Delete_first_node" ;
		cout<<"\n6.Delete_last_node" ;
		cout<<"\n7.Exit" ;
		cout<<"\nEnter the choice :" ;
		cin>>choice ;
		switch(choice)
		{
			case 1 :
				c.accept() ;
				break ;
				
			case 2 :
				cout<<"\n"<<"Doner_id"<<"\t"<<"name"<<"\t"<<"address"<<"\t"<<"phonr_no"<<"\t"<<"amount";
				c.display() ;
				break ;
			case 3 :
				c.search() ;
				break ;
			case 4 :
				c.modify() ;
				break ;
			case 5 :
				c.Delete_first_node();
				break ;
			case 6 :
				c.Delete_last_node() ;
				break ;
			case 7 :
				exit(0) ;
				break ;
			default :
				cout<<"\nWrong choice" ;
		        
		}
		cout<<"\nDo you want to continue (1/0) :";
		cin>>ch ;
	}while(ch == 1);
	
	
	return 0 ;
	
}
