#include<bits/stdc++.h>			//Including header file	
using namespace std;
int main(){				//Main Function
	int n,el,i,j,max;				//Declaring variables
	cout << "Enter size of array " << endl;		//getting the size of array
	cin >> n;					// Storing that value in var n
	int data[n];					//Defining an array of size n
	cout << "Enter the elements " << endl;		
	for (i=0;i<n;i++){				//
		cin >> el;				// Getting all array value and storing it in the prev created array	
		data[i] = el;				//
	}
	int ans[n];					//Creating a new array 'ans'	
	ans[0] = data[0];				//First value of ans = First value in data
	for (i=1;i<n;i++){				//Iterative Loop for n times
		if (ans[i-1] + data[i] > data[i]){	//Condition check if value at 'ans' and corresponding next value in data sum is greater than data[i]
			ans[i] = data[i] + ans[i-1];	//If so, that is the current max sub array sum	
			}
		else{	
			ans[i] = data[i];		// Else value without adding is the max sub array sum
		}
	}
	max = -100000;
	for (i=0;i<n;i++){
		if (max < ans[i]){
			max = ans[i];		//Finding the ultimate max value from the above obtained values
		}
	}
	cout << "Sum of largest subarray is " << max << endl;		// That would be the max sub array sum
	return 0;
}
