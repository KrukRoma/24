#include <iostream>
#include <string>
using namespace std;

class Stack 
{
private:
    char* stackArray;
    int top;
    int capacity;

public:
    Stack(int size) 
    {
        stackArray = new char[size];
        top = -1;
        capacity = size;
    }

    ~Stack() 
    {
        delete[] stackArray;
    }

    bool isEmpty() const 
    {
        return top == -1;
    }

    void push(char ch) 
    {
        if (top < capacity - 1) 
        {
            stackArray[++top] = ch;
        }
    }

    char pop() 
    {
        if (top >= 0) 
        {
            return stackArray[top--];
        }
        return '\0';
    }

    char peek() const 
    {
        if (top >= 0) 
        {
            return stackArray[top];
        }
        return '\0';
    }
};

int main() 
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    Stack stack(input.size());
    size_t errorIndex = input.size();
    bool isBalanced = true;

    for (size_t i = 0; i < input.size(); ++i) 
    {
        char ch = input[i];

        if (ch == '(' || ch == '[' || ch == '{') 
        {
            stack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') 
        {
            if (stack.isEmpty()) 
            {
                isBalanced = false;
                errorIndex = i;
                break;
            }
            else 
            {
                char top = stack.peek();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    isBalanced = false;
                    errorIndex = i;
                    break;
                }
                stack.pop();
            }
        }
        else if (ch == ';') 
        {
            break;
        }
    }

    if (isBalanced && stack.isEmpty()) 
    {
        cout << "The string is correct." << endl;
    }
    else 
    {
        if (errorIndex < input.size()) 
        {
            cout << "Incorrect string up to the first error: " << input.substr(0, errorIndex + 1) << endl;
        }
        else 
        {
            cout << "Incorrect string: not all brackets are balanced" << endl;
        }
    }
}

