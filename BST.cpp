#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct node{
	int value;
	node *left;
	node *right;
	node (){
		left = NULL;
		right = NULL;
	}
};
node *root = new node();
bool flag = true;
void insert(int val){
	if (flag){
		flag = false;
		root->value = val;
		return;
	}
	node *temp = root;
	node *temp1 = new node();
	while (temp != NULL){
		temp1 = temp;
		if (temp->value > val){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	if (temp1->value > val){
		node *ins = new node();
		ins->value = val;
		temp1->left = ins;
	}
	else{
		node *ins = new node();
		ins->value = val;
		temp1->right = ins;
	}
}
void print(){
	queue<node *>q;
	q.push(root);
	while (q.size() > 0){
		node *temp = q.front();
		cout << temp->value << endl;
		q.pop();
		if (temp->left){
			q.push(temp->left);
		}
		if (temp->right){
			q.push(temp->right);
		}
	}
}
bool search(int val){
	node *temp = root;
	while (temp){
		if (temp->value > val){
			temp = temp->left;
		}
		if (temp->value < val){
			temp = temp->right;
		}
		if (temp->value == val){
			return true;
		}
	}
	return false;
}
void remove(int val){
	node *temp = root;
	node *temp1;
	if (!search(val)){
		return;
	}
	while (temp->value != val){
		temp1 = temp;
		if (temp->value > val){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	if (temp->right){
		node *temp1 = temp->right;
		while (temp1->left != NULL){
			temp1 = temp1->left;
		}
		int v = temp1->value;
		remove(temp1->value);
		temp->value = v;
	}
	else if (temp->left){
		node *temp1 = temp->left;
		while (temp1->right != NULL){
			temp1 = temp1->right;
		}
		int v = temp1->value;
		remove(temp1->value);
		temp->value = v;
	}
	else{
		if (temp1->value > val){
			temp1->left = NULL;
		}
		else{
			temp1->right = NULL;
		}
	}
}
int main(){
    int n,i,el;
    cout << "Enter no of nodes you want ";
    cin >> n;
    for (i=0;i<n;i++){
		cin >> el;
		insert(el);
	}
	print();
	remove(1);
	print();
	remove(2);
	print();
    return 0;
} 
