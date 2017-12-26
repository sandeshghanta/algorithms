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
	ans[0] = data[0];
	for (i=1;i<n;i++){
		if (ans[i-1] + data[i] > data[i]){
			ans[i] = data[i] + ans[i-1];
		}
		else{
			ans[i] = data[i];
		}
	}
	max = -100000;
	for (i=0;i<n;i++){
		if (max < ans[i]){
			max = ans[i];
		}
	}
	cout << "Sum of largest subarray is " << max << endl;
	return 0;
}