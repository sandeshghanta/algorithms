#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
ll matrix[100][100][100];
vector<pair<pair<ll,ll>,ll> >edge;
ll dist[100];
ll v,e,src;
int main(){
	cout << "Enter the number of vertices ";
	cin >> v;
	cout << "Enter the number of edges ";
	cin >> e;
	ll a,b,c;
	memset(dist,INT_MAX,v+1);
	cout << "Enter the edges and their weights " << endl;
	for (ll i=0;i<e;i++){
		cin >> a >> b >> c;
		edge.pb(mp(mp(a,b),c));
	}
	cout << "Enter the source vertex ";
	cin >> src;
	dist[src] = 0;
	for (ll i=0;i<v-1;i++){
		for (ll j=0;j<e;j++){
			if (dist[edge[j].ff.ss] > dist[edge[j].ff.ff] + edge[j].ss){
				dist[edge[j].ff.ss] = dist[edge[j].ff.ff] + edge[j].ss;
			}
		}
	}
	bool flag = true;
	for (ll j=0;j<e;j++){
		if (dist[edge[j].ff.ss] > dist[edge[j].ff.ff] + edge[j].ss){
			flag = false;
		}
	}
	if (!flag){
		cout << "Negative cycle exists " << endl;
	}
	else{
		cout << "The minimum weights are " << endl;
		for (ll i=0;i<v;i++){
			cout << dist[i] << " ";
		}
		cout << endl;
	}
}
