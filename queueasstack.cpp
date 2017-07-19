#include<bits/stdc++.h>
using namespace std;
void inser(queue<int>& data)
{
    int el;
    cout << "Enter element to be inserted" << endl;
    cin >> el;
    data.push(el);
    return;
}
void remov(queue<int>& data)
{
    queue<int>temp;
    if (data.size() == 0)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    int siz = data.size();
    for (int i = 0;i<siz-1;i++)
    {
        temp.push(data.front());
        data.pop();
    }
    data.pop();
    siz = temp.size();
    for (int i=0;i<siz;i++)
    {
        data.push(temp.front());
        temp.pop();
    }
    return;
}
void display(queue<int>& data)
{
    cout << "Queue is ";
    queue<int>temp;
    int siz = data.size();
    for (int i=0;i<siz;i++)
    {
        temp.push(data.front());
        data.pop();
    }
    siz = temp.size();
    for (int i=0;i<siz;i++)
    {
        data.push(temp.front());
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    return;
}
int main()
{
    int check=1,choice;
    queue<int>data;
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

