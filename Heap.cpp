#include<bits/stdc++.h>
using namespace std;
class Heap{
	public:
		int arr[100];	//max size of array is 100
		int size;
		Heap(){
			size = 1;
		}
		void insert(int data){
			arr[size] = data;
			check(size);
			size = size + 1;
		}
		void check(int i){
			if (i == 1){
				return;
			}
			if (arr[i/2] < arr[i]){
				int temp = arr[i];
				arr[i] = arr[i/2];
				arr[i/2] = temp;
				check(i/2);
			}
		}
		void checkdown(int i){
			if (size <= 2*i){
				return;
			}
			if (size <= 2*i + 1){
				if (arr[i] < arr[2*i]){
					int temp = arr[i];
					arr[i] = arr[2*i];
					arr[2*i] = temp;
					checkdown(2*i);
				}
			}
			else{
				if (arr[i] < arr[2*i + 1] && arr[2*i] < arr[2*i + 1]){
					int temp = arr[2*i + 1];
					arr[2*i + 1] = arr[i];
					arr[i] = temp;
					checkdown(2*i + 1);
				}
				else if (arr[i] < arr[2*i] && arr[2*i+1] < arr[2*i]){
					int temp = arr[2*i];
					arr[2*i] = arr[i];
					arr[i] = temp;
					checkdown(2*i);
				}
				else{
					//do nothing
				}
			}
		}
		void print(){
			for (int i=1;i<size;i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		void remove(int i){		//removes a particular index
			if (size == 1 || i >= size){
				return;
			}
			arr[i] = arr[size-1];
			size = size - 1;
			checkdown(i);
		}
		void heapsort(){
			if (size == 1){
				cout << endl;
				return;
			}
			cout << arr[1] << " ";
			remove(1);
			heapsort();
		}
};
int main(){
	Heap h;
	h.insert(100);
	h.insert(200);
	h.insert(300);
	h.insert(50);
	h.insert(400);
	h.insert(1000);
	h.insert(20);
	h.insert(500);
	h.insert(10);
	h.insert(5000);
	h.insert(505);
	h.insert(5);
	h.print();
	h.heapsort();
	h.print();
	return 0;
}
 