#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;
int main(){
	ll i,el,j,v,e;
	cout << "Enter no of vertices ";
	cin >> v;
	cout << "Enter no of edges ";
	cin >> e;
	cout << "Enter the edges " << endl;
	vector<ll>data[v];
	vector<ll>revdata[v];
	for (i=0;i<e;i++){
		cin >> el >> j;
		data[el].pb(j);
		revdata[j].pb(el);
	}
	stack<ll>s;
	ll vis[v];
	for (i=0;i<v;i++){
		vis[i] = 0;
	}
	vector<ll>order;
	for (i=0;i<v;i++){
		if (vis[i] == 0){
			s.push(i);
			vis[i] = 1;
			while (s.size() > 0){
				el = s.top();
				bool flag = true;
				for (j=0;j<data[el].size();j++){
					if (vis[data[el][j]] == 0){
						flag = false;
						vis[data[el][j]] = 1;
						s.push(data[el][j]);
					}
				}
				if (flag){
					order.pb(s.top());
					s.pop();
				}
			}		
		}
	}
	for (i=0;i<v;i++){
		vis[i] = 0;
	}
	ll count = 0;
	while (order.size() > 0){
		if (vis[order.back()] == 0){
			count++;
			vis[order.back()] = 1;
			stack<ll>s;
			s.push(order.back());
			cout << "Connected path " << order.back() << " ";
			while (s.size() > 0){
				el = s.top();
				s.pop();
				for (i=0;i<revdata[el].size();i++){
					if (vis[revdata[el][i]] == 0){
						vis[revdata[el][i]] = 1;
						s.push(revdata[el][i]);
						cout << revdata[el][i] << " ";
					}
				}
			}
			cout << endl;
		}
		order.erase(order.end()-1);
	}
	cout << "No of strongly connected components are " << count << endl;
}
