/* Infix To Postfix */ 

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to determine precedence of operators
int precedence(char op) 
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert infix to postfix expression
string infixToPostfix(string infix) 
{
    stack<char> s;  // Stack to store operators
    string postfix; // Resultant postfix expression

    for (char &ch : infix) 
	{
        // If the character is an operand, add it to postfix expression
        if (isalnum(ch)) 
		{
            postfix += ch;
        }
        // If the character is '(', push to stack
        else if (ch == '(') 
		{
            s.push(ch);
        }
        // If the character is ')', pop and add to postfix until '(' is found
        else if (ch == ')') 
		{
            while (!s.empty() && s.top() != '(') 
			{
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        }
        // If the character is an operator
        else if (isOperator(ch)) 
		{
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) 
			{
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    // Pop all remaining operators from the stack
    while (!s.empty()) 
	{
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


// Main driver function
int main() 
{
    string infix;
    int choice;
    
    do 
	{
        cout << "\n--- Infix to Postfix Converter ---\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                cout << "Postfix expression: " << infixToPostfix(infix) << endl;
                break;

            case 2:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 2);
    return 0;
}
