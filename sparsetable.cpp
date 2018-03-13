#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll sparsetable[100][100];
ll data[100];
ll twopow[100];
void init(){
	ll i = 0;
	twopow[0] = 1;
	for (i=1;i<100;i++){
		twopow[i]  = 2*twopow[i-1];
	}
}
void buildtable(ll n){	
	//Building table from bottom
	ll i=0,k;
	for (i=n;i>0;i--){
		for (k=0;i+twopow[k]<=n+1;k++){
			if (k == 0){
				sparsetable[i][k] = data[i];
			}
			else{
				sparsetable[i][k] = sparsetable[i][k-1] + sparsetable[i+twopow[k-1]][k-1];
			}
		}
	}
}
void printtable(ll n){
	ll i=0,k;
	for (i=1;i<=n;i++){
		for (k=0;i+twopow[k]<=n+1;k++){
			cout << sparsetable[i][k] << " ";
		}
		cout << endl;
	}
}
ll query(ll start,ll end){
	ll k=0,ans=0;
	end = end + 1;
	while (start != end){
		if (start + twopow[k] > end){
			ans = ans + sparsetable[start][k-1];
			start = start + twopow[k-1];
			k = 0;
		}
		else{
			k++;
		}
	}
	return ans;
}
int main(){
	init();
	ll i,n,j;
	cout << "Enter no of elements in the array ";
	cin >> n;
	cout << "Enter the elements " << endl;
	for (i=1;i<=n;i++){
		cin >> data[i];
	}
	buildtable(n);
	printtable(n);
	for (i=1;i<=n;i++){
		for (j=i;j<=n;j++){
			cout << "i is " << i << " j is " << j << " " << query(i,j) << endl;
		}
	}
	return 0;
}
