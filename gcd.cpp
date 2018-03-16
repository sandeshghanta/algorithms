#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1000000000+7
using namespace std;
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll gcd(ll a,ll b){			
	if (b == 0){
		return a;
	}
	return gcd(b,a%b);		
}
int main(){
	ll a,b;
	cout << "Enter two numbers" << endl;
	cin >> a >> b;
	//Here a is always supposed to be larger than b, if it is not the case the variables will set them to normal in the next recursion
	cout << gcd(a,b) << endl;
	return 0;
}
