#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1000000000+7
using namespace std;
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll instack[100];
ll vis[100];
ll v,e;
vector<ll>data[100];
ll checkloop(ll index){
	vis[index] = 1;
	instack[index] = 1;
	for (ll i=0;i<data[index].size();i++){
		if (vis[data[index][i]] == 0){
			if (checkloop(data[index][i]) == -1){
				return -1;
			}
		}
		else{
			if (instack[data[index][i]] == 1){
				cout << "Loop Exists at " << index << " and " << data[index][i] << endl;
				return -1;
			}
		}
	}
	instack[index] = -1;
	return 0;
}
int main(){
	ll i,j,el;
	cout << "Enter no of vertices ";
	cin >> v;
	cout << "Enter no of edges ";
	cin >> e;
	cout << "Enter the edges" << endl;
	for (i=0;i<e;i++){
		cin >> j >> el;
		data[j].pb(el);
	}
	for (i=0;i<v;i++){
		if (vis[i] == 0){
			if (checkloop(i) == -1){
				return 0;
			}
		}
	}
	return 0;
}
