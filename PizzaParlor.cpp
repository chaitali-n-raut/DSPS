#include <iostream>
#include <cstring>
using namespace std;

#define MAX 5  

class Order
{
public:
    char customername[50];
    char pizzaname[30];
    string pizzatype;
    int pizzasize;
    int quantity;

    void takeOrder()
    {
        cout << "Enter customer name: ";
        cin >> customername;

        cout << "Enter pizza type: ";
        cin >> pizzatype;

        cout << "Enter pizza size (1 for Small, 2 for Medium, 3 for Large): ";
        cin >> pizzasize;

        cout << "Enter pizza quantity: ";
        cin >> quantity;
    }

    void displayOrder()
    {
        cout << "Customer Name: " << customername << endl;
        cout << "Pizza Type: " << pizzatype << endl;
        cout << "Pizza Size: ";
        switch (pizzasize) {
            case 1: cout << "Small"; break;
            case 2: cout << "Medium"; break;
            case 3: cout << "Large"; break;
            default: cout << "Unknown size"; break;
        }
        cout << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

class PizzaParlor
{
    int front, rear;
    Order queue[MAX]; 

public:
    PizzaParlor()
    {
        front = -1;
        rear = -1;
    }

    
    void rear_insertion(Order order)
    {
        if (rear == MAX - 1) {
            cout << "\nQueue is overflow, cannot place more orders.";
        } else {
            if (front == -1) front = 0;  
            rear++;
            queue[rear] = order;
            cout << "Order placed successfully.\n";
        }
    }

    
    void front_deletion()
    {
        if (front == -1 || front > rear) {
            cout << "\nNo orders to serve.";
        } else {
            cout << "\nServing order for:\n";
            queue[front].displayOrder();
            front++;
            if (front > rear) { 
                front = -1;
                rear = -1;
            }
        }
    }


    void displayOrders()
    {
        if (front == -1 || front > rear) {
            cout << "\nNo current orders.\n";
        } else {
            cout << "\nCurrent orders in queue:\n";
            for (int i = front; i <= rear; i++) {
                cout << "\nOrder " << (i - front + 1) << ":\n";
                queue[i].displayOrder();
            }
            cout << endl;
        }
    }

    
    void placeOrder()
    {
        Order newOrder;
        newOrder.takeOrder();
        rear_insertion(newOrder);
    }

    
    void serveOrder()
    {
        front_deletion();
    }
};

int main()
{
    PizzaParlor parlor;
    int choice;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                parlor.placeOrder();
                break;

            case 2:
                parlor.serveOrder();
                break;

            case 3:
                parlor.displayOrders();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}