#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	string n,m;
	ll i,j,len;
	cout << "Enter the string to be checked ";
	cin >> n;
	cout << "Enter the string to check for ";
	cin >> m;
	ll lps[m.size()];
	lps[0] = 0;
	len = 0;
	//Building the LPS array
	for (i=1;i<m.size();){
		if (m[len] == m[i]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if (len != 0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	j = 0;
	for (i=0;i<n.size();){
		if (n[i] == m[j]){
			j++;
			i++;
			if (j == m.size()){
				cout << "Found " << m << " from index " << i - j << " to " << i - 1 << endl;
				j = lps[j-1];
			}
		}
		else{
			if (j != 0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
}
