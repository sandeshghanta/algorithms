#include<bits/stdc++.h>
using namespace std;
void inser(stack<int>& data)
{
   int el;
   cout << "Enter element to be inserted" << endl;
   cin >> el;
   data.push(el);
   return;
}
void remov(stack<int>& data)
{
    if (data.size() == 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    stack<int>temp;
    int siz = data.size();
    for (int i=0;i<siz;i++)
    {
        temp.push(data.top());
        data.pop();
    }
    temp.pop();
    siz = temp.size();
    for (int i=0;i<siz;i++)
    {
        data.push(temp.top());
        temp.pop();
    }
    return;
}
void display(stack<int>& data)
{
    stack<int>temp;
    cout << "Now Queue is ";
    int siz = data.size();
    for (int i = 0;i<siz;i++)
    {
        temp.push(data.top());
        data.pop();
    }
    siz = temp.size();
    for (int i=0;i<siz;i++)
    {
        data.push(temp.top());
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    return;
}
int main ()
{
    stack<int>data;
    int check = 1,choice;
    while (check == 1)
    {
        cout << "Press 1 to insert element" << endl;
        cout << "Press 2 to remove element" << endl;
        cout << "Press 3 to exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            inser(data);
        }
        if (choice == 2)
        {
            remov(data);
        }
        if (choice == 3)
        {
            break;
        }
        display(data);
    }
    return 0;
}
