#include<bits/stdc++.h>
using namespace std;
int data[100];
int segtree[200];
void build(int nodeindex,int start,int end){
	int mid = (start + end)/2;
	if (start == end){
		segtree[nodeindex] = data[start];
	}
	else{
		build(2*nodeindex,start,mid);
		build(2*nodeindex+1,mid+1,end);
		segtree[nodeindex] = segtree[2*nodeindex] + segtree[2*nodeindex + 1];
	}
}
void updateindex(int nodeindex,int nodestart,int nodeend,int index,int change){
	int mid = (nodestart + nodeend)/2;
	if (nodestart == nodeend){
		segtree[nodestart] += change;
		return;
	}
	if (index > mid){
		updateindex(2*nodeindex + 1,mid+1,nodeend,index,change);
	}
	else{
		updateindex(2*nodeindex,nodestart,mid,index,change);
	}
	segtree[nodeindex] = segtree[2*nodeindex] + segtree[2*nodeindex + 1];
}
void updaterange(int nodeindex,int nodestart,int nodeend,int l,int r,int change){
	if (nodestart > nodeend || nodestart > r || nodeend < l){
		return;	//node lies completely outside the range l-r
	}
	if (nodestart == nodeend){
		segtree[nodeindex] += change;	//leaf node
		return;
	}
	int mid = (nodestart + nodeend)/2;
	updaterange(nodeindex*2,nodestart,mid,l,r,change);
	updaterange(nodeindex*2+1,mid+1,nodeend,l,r,change);		
	segtree[nodeindex] = segtree[nodeindex*2] + segtree[nodeindex*2 + 1];
}
int query(int nodeindex,int nodestart,int nodeend,int l,int r){
	if (nodestart > nodeend || nodestart > r || nodeend < l){
		return 0;
	}
	if (l <= nodestart && r >= nodeend){
		return segtree[nodeindex];
	}
	int mid = (nodestart + nodeend)/2;
	int q1 = query(2*nodeindex,nodestart,mid,l,r);
	int q2 = query(2*nodeindex+1,mid+1,nodeend,l,r);
	return q1 + q2;
}
int main(){
	int n,i;
	cout << "Enter the range " << endl;
	cin >> n;
	cout << "Enter values " << endl;
	for (i=1;i<=n;i++){
		cin >> data[i];
	}
	build(1,1,n);
	cout << query(1,1,n,1,n) << endl;
}
