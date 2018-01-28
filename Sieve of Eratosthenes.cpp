#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j;
	cin >> n;
	int data[n+1];
	for (i=1;i<n+1;i++){
		data[i] = 1;
	}
	data[1] = 0;
	for (i=2;i<=sqrt(n);i++){
		if (data[i] == 1){
			for (j=2*i;j<=n;j+=i){
				data[j]=0;
			}
		}
	}
	for (i=1;i<=n;i++){
		if (data[i] == 1){
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}