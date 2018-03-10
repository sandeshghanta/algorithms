#include<bits/stdc++.h>
using namespace std;
struct node{
	int value;
	int priority;
	node *l;
	node *r;
};
bool flag = true;
void split(node *t,node *&l,node *&r,int key){
	if (!t){
		l = NULL;
		r = NULL;
		return;
	}
	if (t->value < key){
		split(t->r,t->r,r,key);
		l = t;
	}
	else{
		split(t->l,l,t->l,key);
		r = t;
	}
}
void insert(node *&t, node* it){
	if (!t){
		t = it;
		return;
	}
	if (t->priority < it->priority){
		split(t,it->l,it->r,it->value);
		t = it;
	}
	else{
		if (t->value > it->value){
			insert(t->l,it);
		}
		else{
			insert(t->r,it);
		}
	}
}
void merge(node *&t,node *&l,node *&r){
	if (!l || !r){
		t = l?l:r;
		return;
	}
	if (l->priority > r->priority){
		merge(l->r,l->r,r);
		t = l;
	}
	else{
		merge(r->l,l,r->l);
		t = r;
	}	
}
void erase(node *&t,int key){
	if (!t){
		return;
	}
	if (t->value == key){
		node* temp = t;
		cout << "printing temp " << temp->value << " " << temp->priority << endl;
		merge(t,t->l,t->r);
		free(temp);
		cout << "printing temp " << temp->value << " " << temp->priority << endl;
	}
	else{
		if (t->value > key){
			erase(t->l,key);
		}
		else{
			erase(t->r,key);
		}
	}
}
node * create(int val){
	node* temp = new node();
	temp->value = val;
	temp->priority = rand();
	return temp;
}
void print(node *temp){
	cout << "starting print job" << endl;
	queue<node *>q;
	q.push(temp);
	while (q.size() > 0){
		node *el = q.front();
		q.pop();
		cout << el->value << " " << el->priority << endl;
		if (el->l){
			q.push(el->l);
		}
		if (el->r){
			q.push(el->r);
		}
	}
	cout << "ending print job" << endl;
}
node * init(int value){
	node *temp = new node();
	temp->value = value;
	temp->priority = rand();
	return temp;
}
int main(){
	int n,i,el;
	cout << "Enter the number of nodes ";
	cin >> n;
	node *root = NULL;
	for (i=0;i<n;i++){
		cin >> el;
		node* temp = init(el);
		insert(root,temp);
	}
	print(root);
	erase(root,5);
	print(root);
	return 0;
}
