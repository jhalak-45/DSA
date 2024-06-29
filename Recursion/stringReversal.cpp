#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    char *stack;
    int size;
    int top;

public:
    Stack(int s)
    {
        size = s;
        stack = new char[size];
        top = -1;
    }

    ~Stack()
    {
        delete[] stack;
    }

    void push(char data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!\n";
            return;
        }
        else
        {
            top = top + 1;
            stack[top] = data;
        }
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!\n";
            return '\0';
        }
        else
        {
            char data = stack[top];
            top = top - 1;

            return data;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

string reverseString(const string &str)
{
    int length = str.length();
    Stack stack(length);

    // Push each character of the input string onto the stack
    for (int i = 0; i < length; ++i)
    {
        stack.push(str[i]);
    }

    string revStr;
    while (!stack.isEmpty())
    {
        revStr += stack.pop();
    }

    return revStr;
}

int main()
{
    string str = "Hello, world!";
    string reversed = reverseString(str);

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
