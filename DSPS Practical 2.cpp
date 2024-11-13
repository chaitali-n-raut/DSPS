/* College library has N books. Write C/C++ program to store the cost of books in array in ascending order.
 Books are to be arranged in descending order of their cost. Write function for : 
A) Copy costs of books those with cost less than 500 in new array
a) Delete the duplicate entries using temporary array
b) Delete duplicate entries without using temporary array
c) Count number of books with cost more than 500 */

#include <iostream>
#include<cstring>
using namespace std;
int n;
class book 
{
	private:
		int cost; 
		char name[10];
		char auth[10];
		
	public:
		void accept(); 
		void display(); 
		void asc(int n); 
		void desc(int n);
		void cpyless(int n);
		int  count(int n);
		void temparray();
		void deldup(int n);
}b[100],c[100],t[100];
  
void book::accept()
{
    cout << "Enter the Name, Author and Cost of the Book ";
    cin >>name>>auth>>cost;
}
 void book:: display()
 {
    cout<<"\n"<<name<<"\t"<<auth<<"\t"<<cost;

 } 

void book:: asc(int n)
{   
	book temp;
    for (int i = 0; i <n-1; i++)
    {
        for (int j =i+1; j <n; j++)
        {
            if(b[i].cost>b[j].cost)
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
   for (int i = 0; i < n; i++)
    {
        b[i].display();
    }
}
void book:: desc(int n)
{   book temp;
    for (int i = 0; i <n-1; i++)
    {
        for (int j =i+1; j <n; j++)
        {
            if(b[i].cost<b[j].cost)
            {
                temp=b[j];
                b[j]=b[i];
                b[i]=temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        b[i].display();
    }
}
 void book:: cpyless(int n)
 {   int j=0;
    for (int i = 0; i <n; i++)
    {
        if(b[i].cost<500)
        {
			c[j]=b[i];
            j++;
        }
        
    }
    for (int i = 0; i < j; i++)
    {
        c[i].display();
    }
 }
 int book:: count(int n)
 {
   int countt=0;
    for (int i = 0; i <n; i++)
    {
        if(b[i].cost>500)
        {
			countt++;
        }
        
    }
    cout<<countt<<"Books having price greater than 500 ";
    return countt;
    
 }
 void book::temparray() {  
    int y,i,k=0,j = 0;  
    t[0] = b[0];  

    for( i = 1; i < n; i++) {
        y=0;
        for(j=0;j<=k;j++)
        {
        if(strcmp(b[i].name , t[j].name)==0)
         {
           y=1;
            break;
        }
       
        }
         if(y==0)
        {
            k++;  
            t[k] = b[i];
           
        }
       
    }
    for(i=0;i<=k;i++)
    t[i].display();
}


void book::deldup(int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (b[i].name == b[j].name && b[i].auth == b[j].auth) 
            {
                for (int k = j; k < n - 1; k++) {
                    b[k] = b[k + 1];
                }
                n--; 
                j--; 
            }
        }
    }
     for (int i = 0; i<n ; i++)
    {
        b[i].display();
    }
}
 int main()
 {  book temp;
    int ch,i;
    do
    { 
        cout<<"\n1.Enter book details\n2.Display book details\n3.Arrange books in ascending order";
        cout<<"\n4.Arrange books in descending order\n5.Copy books <500 in new array\n6.count books having price>500";
		cout<<"\n7.Delete similar record using temprory array\n8.Delete without temprory array\n9.exit\n";
		cout<<" \nEnter your choice :  ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter no. of books you want to insert data\n";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                b[i].accept();
            }
            break;
            case 2:
             cout<<"\n"<<"name\tauthor\tcost";
            
            for(int i=0;i<n;i++)
            {
                b[i].display();
            }
            break;
            case 3:
				b[0].asc(n);
				break;
            case 4:
				b[0].desc(n);
				break;
            case 5:
				b[0].cpyless(n);
				break;
            case 6:
				b[0].count(n);
				break;
            case 7:
				t[0].temparray();
				break;
            case 8:
				b[0].deldup(n);
				break;
            case 9:
				return 0;

            default:
				cout<<"wrong chpice";
        }
    }while(ch!=9); 
 }
