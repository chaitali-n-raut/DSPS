//Dubly linked list 
#include<iostream>
#include<string>
using namespace std ;
class charity
{
	int did, amount ;
	long int phone_no ;
	string name, add ;
	charity *next, *prev ;
	public :
		void accept();
		void display() ;
		void search();
		void modify();
		void del();
} *start, *endd ;
void charity :: accept()
{
	charity *nnode ;
	nnode = new charity ;
	cout<<"Enetr the details :" ;
	cout<<"\nEnte the Doner id :" ;
	cin>>nnode -> did ;
	cout<<"\nEnte the Doner name :" ;
	cin>>nnode -> name ;
	cout<<"\nEnte the Doner address :" ;
	cin>>nnode -> add ;
	cout<<"\nEnte the Doner phone_no :" ;
	cin>>nnode -> phone_no ;
	cout<<"\nEnte the Doneting amount :" ;
	cin>>nnode -> amount ;
	
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
void charity :: display()
{
	charity *temp ;
	temp = start ;
	if(temp == NULL)
	{
		cout<<"\nNO datails found";
	}
	else
	{
		
		while(temp!= NULL)
		{
			cout<<"\n"<<temp->did<<"\t"<<temp->name<<"\t"<<temp->add<<"\t"<<temp->phone_no<<"\t"<<temp->amount ;
			temp = temp->next ;
		}
	}
}
void charity :: search()
{
	charity *temp ; 
	int flag = 0 ;
	int id ;
	cout<<"\nEnter the id do you want to search :";
	cin>>id ;
	temp = start ;
	while(temp != NULL)
	{
		if(temp->did == id)
		{
			flag =1 ;
			cout<<"\nData is found" ;
			cout<<"\n"<<"Doner_id"<<"\t"<<"name"<<"\t"<<"address"<<"\t"<<"phonr_no"<<"\t"<<"amount";
			cout<<"\n"<<temp->did<<"\t"<<temp->name<<"\t"<<temp->add<<"\t"<<temp->phone_no<<"\t"<<temp->amount ;
			break ;
		}
		temp = temp->next ;
	}
	if(flag == 0)
	{
		cout<<"\nData is not found" ;
	}
}
void charity :: modify()
{
	charity *temp ;
    int flag = 0 ;
	int id ;
	cout<<"\nEnter the id do you want to modify :";
	cin>>id ;
	temp = start ;
	while(temp != NULL)
	{
		if(temp->did == id)
		{
			flag = 1 ;
			cout<<"Enetr the details :" ;
	        cout<<"\nEnte the Doner id :" ;
			cin>>temp -> did ;
			cout<<"\nEnte the Doner name :" ;
			cin>>temp -> name ;
			cout<<"\nEnte the Doner address :" ;
			cin>>temp -> add ;
			cout<<"\nEnte the Doner phone_no :" ;
			cin>>temp -> phone_no ;
			cout<<"\nEnte the Doneting amount :" ;
			cin>>temp
			 -> amount ;
			break ;
		}
		temp = temp->next ;
	}
	if(flag == 0)
	{
		cout<<"\nData is not found" ;
	}	
}
void charity :: del()
{
	charity *temp, *p ;
    int flag = 0 ;
	int id ;
	cout<<"\nEnter the id do you want to delete :";
	cin>>id ;
	temp = start ;
	while(temp != NULL)
	{
		if(temp->did == id)
		{
			flag = 1;
			break ;
		}
		p = temp ;
		temp = temp->next ;
		
	}
	p->next = temp -> next ;
	temp->next->prev ;
	delete(temp);
		if(flag == 0)
	{
		cout<<"\nData is not found" ;
	}	
}
int main()
{
	charity c ;
	int ch, choice ;
	do
	{
		cout<<"\n-----------MENU-----------" ;
		cout<<"\n1.Accept" ;
		cout<<"\n2.Display" ;
		cout<<"\n3.Search" ;
		cout<<"\n4.Modify" ;
		cout<<"\n5.Delete" ;
		cout<<"\n6.Exit" ;
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
				c.del();
				break ;
			case 6 :
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
