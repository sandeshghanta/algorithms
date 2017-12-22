#include<bits/stdc++.h>
using namespace std;
void divide(string num,int div){
	int temp=0;
	string quot = "";
	for (int i=0;i<num.size();){
		if (temp < div){
			if (quot != ""){	//to avoid leading zeroes
				quot = quot + '0'; 
			}
			temp = temp*10 + (num[i]-48);
			i++;
		}
		else{
			quot = quot + (char)((temp/div)+48);
			temp = temp%div;
			temp = temp*10 + (num[i]-48);
			i++;
		}
	}
	if (temp >= div){
		quot = quot + (char)((temp/div)+48);
		temp = temp%div;
	}
	cout << "quotient is " << quot << endl;
	cout << "remainder is " << temp << endl;
}
int main(){
	string num;
	int div;
	cout << "Enter a big number " << endl;
	cin >> num;
	cout << "Enter a number " << endl;
	cin >> div;
	divide(num,div);
	return 0;
}