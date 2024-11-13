/* Double ended Queue is a linear list in which addition and deletions of elements may be made at either end.  
	Obtain a data representation mapping a dequeue into 1 Dimensional array. Write C++ program to simulate dequeue	
	with functions to add and delete the elements from either end of the dequeue. 
	below functions we have to implement in dequeue : 
	1) Insertion at front 
	2) Insertion at rear
	3) Deletion at front 
	4) Deletion at rear 
	5) Element at front
	6) Element at rear */
	
#include <iostream>
using namespace std;

#define SIZE 10  // Maximum size of the dequeue

class Deque 
{
    int arr[SIZE];
    int front, rear;

public:
    Deque() 
	{
        front = -1;
        rear = -1;
    }

    bool isFull() 
	{
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }
    bool isEmpty() 
	{
        return front == -1;
    }
    void insertFront(int element) 
	{
        if (isFull()) 
		{
            cout << "Deque is full, cannot insert at front.\n";
            return;
        }

        if (isEmpty()) 
		{
            front = rear = 0;
        } 
		else if (front == 0) 
		{
            front = SIZE - 1;
        } 
		else 
		{
            front--;
        }

        arr[front] = element;
    }
    void insertRear(int element) 
	{
        if (isFull()) 
		{
            cout << "Deque is full, cannot insert at rear.\n";
            return;
        }

        if (isEmpty()) 
		{
            front = rear = 0;
        } 
		else if (rear == SIZE - 1) 
		{
            rear = 0;
        } 
		else 
		{
            rear++;
        }
        arr[rear] = element;
    }

    void deleteFront() 
	{
        if (isEmpty()) 
		{
            cout << "Deque is empty, cannot delete from front.\n";
            return;
        }

        cout << "Deleted element from front: " << arr[front] << endl;

        if (front == rear) 
		{
            front = rear = -1;  // Reset when deque becomes empty
        } 
		else if (front == SIZE - 1) 
		{
            front = 0;
        } 
		else 
		{
            front++;
        }
    }

    void deleteRear() 
	{
        if (isEmpty()) 
		{
            cout << "Deque is empty, cannot delete from rear.\n";
            return;
        }

        cout << "Deleted element from rear: " << arr[rear] << endl;

        if (front == rear) 
		{
            front = rear = -1;  // Reset when deque becomes empty
        } 
		else if (rear == 0) 
		{
            rear = SIZE - 1;
        } 
		else 
		{
            rear--;
        }
    }

    void getFront() 
	{
        if (isEmpty()) 
		{
            cout << "Deque is empty.\n";
        } 
		else 
		{
            cout << "Element at front: " << arr[front] << endl;
        }
    }

    void getRear() 
	{
        if (isEmpty()) 
		{
            cout << "Deque is empty.\n";
        } 
		else 
		{
            cout << "Element at rear: " << arr[rear] << endl;
        }
    }
};

int main() 
{
    Deque dq;
    int choice, element;

    do 
	{
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n";
        cout << "5. Get element at front\n6. Get element at rear\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
        case 1:
            cout << "Enter element to insert at front: ";
            cin >> element;
            dq.insertFront(element);
            break;

        case 2:
            cout << "Enter element to insert at rear: ";
            cin >> element;
            dq.insertRear(element);
            break;

        case 3:
            dq.deleteFront();
            break;

        case 4:
            dq.deleteRear();
            break;

        case 5:
            dq.getFront();
            break;

        case 6:
            dq.getRear();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

