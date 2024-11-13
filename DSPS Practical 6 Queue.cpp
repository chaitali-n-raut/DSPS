/* Pizza Parler accepting maximum m orders. Orders are sort in First Come First Serve Basis. Order once placed Cannot be cancelled.
 Write a C++ program to simulate the system using queue with the help of Array.
Input : 1) Maximum m orders.
		2) The sequence of m orders.
Output : 1) Sequence of order accepting the pizza parler.
		 2) The sequence of orders are served.*/

#include<iostream>
using namespace std;

class PizzaParlor 
{
    int front, rear, maxOrders;
    int *orders;

public:
    PizzaParlor(int M) 
	{
        maxOrders = M;
        front = rear = -1;
        orders = new int[maxOrders];
    }

    bool isFull() // Queue is full 
	{
        return (rear == maxOrders - 1);
    }

    bool isEmpty() // Queue is Empty 
	{
        return (front == -1 || front > rear);
    }
    void placeOrder(int orderID) 
	{
        if (isFull()) 
		{
            cout << "Order queue is full. Cannot place more orders.\n";
        } 
		else 
		{
            if (front == -1) front = 0; // Initialize front if first order
            orders[++rear] = orderID;
            cout << "Order " << orderID << " placed.\n";
        }
    }
    void serveOrder() 
	{
        if (isEmpty()) 
		{
            cout << "No orders to serve, ( Queue is Empty) .\n";
        } 
		else 
		{
            cout << "Order " << orders[front] << " served.\n";
            front++;
        }
    }
    ~PizzaParlor() 
	{
        delete[] orders;
    }
};

int main() 
{
    int M, choice, orderID;
    
    cout << "Enter maximum number of orders: ";
    cin >> M;

    PizzaParlor parlor(M);
    do 
	{
        cout << "\n1. Place Order\n2. Serve Order\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
        case 1:
            cout << "Enter order ID: ";
            cin >> orderID;
            parlor.placeOrder(orderID);
            break;
        case 2:
            parlor.serveOrder();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
