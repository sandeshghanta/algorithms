#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,el,i,j,max;
	cout << "Enter size of array " << endl;
	cin >> n;
	int data[n];
	cout << "Enter the elements " << endl;
	for (i=0;i<n;i++){
		cin >> el;
		data[i] = el;
	}
	int ans[n];
	ans[0] = 1;
	for (i=1;i<n;i++){
		max = 1;
		for (j=0;j<i;j++){
			if (data[i] > data[j] && ans[j] + 1> max){
				max = ans[j] + 1;
			}
		}
		ans[j] = max;
	}
	max = -1;
	for (i=0;i<n;i++){
		if (max < ans[i]){
			max = ans[i];
		}
	}
	cout << "Longest increasing subsequence is " << max << endl;
	return 0;
}
