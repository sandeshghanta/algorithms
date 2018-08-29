//Reference: https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,sum=0;
	cout << "Enter the number of numbers ";
	cin >> n;
	ll data[n];
	cout << "Enter the numbers " << endl;
	for (ll i=0;i<n;i++){
		cin >> data[i];
		sum += data[i];
	}
	bool dp[n+1][sum+1];
	memset(dp, false, sizeof dp);
	for (ll i=1;i<=n;i++){
		dp[i][0] = true;
	}
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=sum;j++){
			dp[i][j] = dp[i-1][j];
			if (j >= data[i-1]){
				dp[i][j] |= dp[i-1][j-data[i-1]];
			}
		}
	}
	ll ans;
	for (ll i=sum/2;i>=0;i--){
		if (dp[n][i]){
			ans = sum - 2*i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
