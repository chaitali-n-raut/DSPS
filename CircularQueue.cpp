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

    bool isFull() // Circular queue is full
    {
        return ((rear + 1) % maxOrders == front);
    }

    bool isEmpty() // Circular queue is empty
    {
        return (front == -1);
    }

    void placeOrder(int orderID)
    {
        if (isFull())
        {
            cout << "Order queue is full. Cannot place more orders.\n";
        }
        else
        {
            if (isEmpty())
                front = 0; // Initialize front if first order

            rear = (rear + 1) % maxOrders; // Move rear circularly
            orders[rear] = orderID;
            cout << "Order " << orderID << " placed.\n";
        }
    }

    void serveOrder()
    {
        if (isEmpty())
        {
            cout << "No orders to serve, (Queue is Empty).\n";
        }
        else
        {
            cout << "Order " << orders[front] << " served.\n";
            if (front == rear) // Only one order left, now queue becomes empty
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % maxOrders; // Move front circularly
            }
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
