#include<bits/stdc++.h>
int n = 80;
int pos[80];
int data[80][80];
int check(int p)
{
    int i,j;
    std::vector <int> pos;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (data[i][j] == 1)
            {
                pos.push_back(i*n+j);
            }
        }
    }
    pos.push_back(p);
    for (i=0;i<pos.size()-1;i++)
    {
        for (j=i+1;j<pos.size();j++)
        {
            if (pos[i]/n == pos[j]/n)
            {
                return 0;
            }
            if (pos[i]%n == pos[j]%n)
            {
                return 0;
            }
            if (abs(pos[i]-pos[j]) == n - 1 || abs(pos[i]-pos[j]) == n + 1)
            {
                return 0;
            }
            if (pos[i] == pos[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int board(int posi)
{
    int k;
    if (posi == n)
    {
        return 1;
    }
    for (int i=0;i<n*n;i++)
    {
      //  std::cout << "i is " << i << std::endl;
        if (check(i) == 1)
        {
        //    std::cout << "i after checking is " << i << std::endl;
            data[i/n][i%n] = 1;
            for (k=n-1;k>=0;k--)
            {
                if (pos[k] != -1)
                {
                    break;
                }
            }
            pos[k+1] = i;
            int t = board(posi+1);
            if (t == 1)
            {
                return 1;
            }
        }
    }
    for (k=n-1;k>=0;k--)
    {
        if (pos[k] != -1)
        {
            data[(pos[k])/n][(pos[k])%n] = 0;
            pos[k] = -1;
            break;
        }
    }
    return 0;
}
int main()
{
    int n,i,j;
    std::cout << "Enter size of board you want" << std::endl;
    std::cin >> n;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            data[i][j] = 0;
        }
    }
    for (i=0;i<n;i++)
    {
        pos[i] = -1;
    }
    board(0);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
