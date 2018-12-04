#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll data[100];
struct node{
	ll start;
	ll end;
	ll value;
	node *left;
	node *right;
};
node* build(int l,int r){
	node* temp = new node();
	temp->start = l;
	temp->end = r;
	if (l == r){
		temp->value = data[l];
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	ll mid = (l+r)/2;
	temp->left = build(l,mid);
	temp->right = build(mid+1,r);
	temp->value = temp->left->value + temp->right->value;
	return temp;
}
void updateindex(node* temp,int index,int change){
	if (!temp){
		return;
	}
	if (temp->start == temp->end){
		temp->value += change;
	}
	ll mid = (temp->start + temp->end)/2;
	if (index > mid){
		updateindex(temp->right,index,change);
	}
	else{
		updateindex(temp->left,index,change);
	}
	ll tmp = 0;
	if (temp->right){
		tmp += temp->right->value;
	}
	if (temp->left){
		tmp += temp->left->value;
	}
	temp->value = tmp;
}
void updaterange(node* temp,int l,int r,int change){
	if (!temp){
		return;
	}
	if (l > temp->end || temp->start > r){
		return;
	}
	if (temp->start == temp->end){
		temp->value += change;
		return;
	}
	updaterange(temp->left,l,r,change);
	updaterange(temp->right,l,r,change);
	temp->value = temp->left->value + temp->right->value;
}
int query(node* temp,int l,int r){
	if (!temp){
		return 0;
	}
	if (l > temp->end || temp->start > r){
		return 0;
	}
	if (l <= temp->start && r >= temp->end){
		return temp->value;
	}
	ll q1 = query(temp->left,l,r);
	ll q2 = query(temp->right,l,r);
	return q1 + q2;
}
int main(){
	ll n,i,j;
	cout << "Enter the number of elements " << endl;
	cin >> n;
	for (i=0;i<n;i++){
		cin >> data[i+1];
	}
	node* root = build(1,n);
	return 0;
}
