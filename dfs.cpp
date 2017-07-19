#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m,a,b,temp,i;
    stack <int> trav;
    cout << "Enter how many nodes you want" << endl;
    cin >> n;
    cout << "Enter how many edges you want" << endl;
    cin >> m;
    vector<int> data[n];
    for (i=0;i<m;i++)
    {
        cout << "Enter an edge" << endl;
        cin >> a >> b;
        data[a-1].push_back(b);
        data[b-1].push_back(a);
    }
    trav.push(temp);
    int visited[n];
    for (i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    cout << "data is " << endl;
    for (i=0;i<n;i++)
    {
        for (int j = 0;j<data[i].size();j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter from which node you want to start" << endl;
    cin >> temp;
    trav.push(temp);
    while (trav.size() != 0)
    {
        temp = trav.top();
        trav.pop();
        for (i=0;i<data[temp-1].size();i++)
        {
            if (visited[data[temp-1][i]] != 1)
            {
                trav.push(data[temp-1][i]);
            }
        }
        if (visited[temp-1] != 1)
        {
            visited[temp-1] = 1;
            cout << temp << " ";
        }
    }
    cout << endl;
    return 0;
}
