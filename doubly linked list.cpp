#include<bits/stdc++.h>
using namespace std;
class Node{			//Defining a node
	public:
		int data;
		Node* next;
		Node* prev;
		Node(){		//Constructor
			data = 0;
			next = NULL;
			prev = NULL;
		}
		Node(int x){	//Constructor
			data = x;
			next = NULL;
			prev = NULL;
		}
};
class List{
	public:
		Node* head = NULL;
		void append(int data){
			Node* newnode = new Node(data);
			Node* temp = head;
			if (temp == NULL){
				head = newnode;
				return;
			}
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
		}
		void print(){			//Function to print the doubly linked list
			Node* temp = head;
			while (temp != NULL){
				cout << temp->data << " ";
				temp = temp->next;	
			}
			cout << endl;
		}
		void delete_value(int value){ 	//Deletes all the nodes having a particular value
			Node* temp = head;
			Node* temp1 = NULL;
			bool flag;
			while (temp != NULL){
				flag = true;
				if (temp->data == value){
					if (temp1 == NULL){
						head = head->next;
						//cout << "hello" << endl;
						head->prev = NULL;
						//cout << "world" << endl;
					}
					else{
						temp1->next = temp->next;
						if (temp->next != NULL){
							temp->next->prev = temp1;
						}
					}
					flag = false;
				}
				if (flag){
					temp1 = temp;
				}
				temp = temp->next;	
			}
		}
		int getsize(){			//Method to find the size of the doubly linked list
			Node* temp = head;
			int size = 0;
			while (temp != NULL){
				temp = temp->next;
				size = size + 1;
			}
			return size;
		}
		void append_at_head(int data){		//Adding a node at the beginning of the doubly Linked List
			Node* newnode = new Node(data);
			if (head == NULL){
				head = newnode;
			}
			else{
				newnode->next = head;
				head->prev = newnode;
				head = newnode;
			}
		}
};
int main(){		
	List l;		//Defining an object l of class List	
	l.append(100);		//Adding nodes
	l.append(100);
	l.append(100);
	l.append(100);
	l.append(100);
	l.append(100);
	l.append(100);
	l.append(100);
	l.append(200);
	l.append(300);
	l.append(100);
	l.append(400);
	l.append(300);
	l.append(100);
	l.append(400);
	l.append(100);
	l.append(200);
	l.append(200);
	l.append(300);
	l.append(200);
	l.append(300);
	l.append(100);
	l.append(400);
	l.append(300);
	l.append(100);
	l.append(400);
	l.append(100);
	l.append(400);
	l.append(100);
	l.append(100);
	l.print();
	l.delete_value(100);
	l.print();
	l.delete_value(200);
	l.print();
	l.delete_value(400);
	l.print();
	cout << l.getsize() << endl;
	l.append_at_head(100);
	l.print();
	return 0;
} 
