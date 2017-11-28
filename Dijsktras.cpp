/*
	Note to self:
		The Heap takes the given container and stores the most priority element in the first index.
		Then when we do pop_heap() first the v.begin()(i.e the element with most priority) is swapped with the element at v.end()
		Then the elements from v.begin() to v.end() - 1 are rearranged so that they again form a Heap		
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int index;
	int weight;
};
struct Comp
{
   bool operator()(node& s1,node& s2)
   {
       return s1.weight > s2.weight; //This is required
   }
};
void print(vector<node> temp){
	for (int i=0;i<temp.size();i++){
		cout << temp[i].index << " ";
	}
	cout << endl;
}
int main(){
	int v,e,a,b,w,source;
	cout << "Enter the number of vertices ";
	cin >> v;
	cout << "Enter the number of edges ";
	cin >> e;
	cout << "Enter the edges followed by their weights" << endl;
	int dis[v+1];
	int vis[v+1];
	vector<node>vec;
	vector<int>data[v+1];
	vector<int>weight[v+1];
	for (int i=1;i<=v;i++){
		dis[i] = 9999999;
		vis[i] = 0;
	}
	for (int i=0;i<e;i++){
		cin >> a >> b >> w;
		data[a].push_back(b);
		data[b].push_back(a);
		weight[a].push_back(w);
		weight[b].push_back(w);
	}
	cout << "Enter the source vertex ";
	cin >> source;
	node temp;
	temp.index = source;
	temp.weight = 0;
	vec.push_back(temp);
	make_heap(vec.begin(),vec.end(),Comp());
	dis[source] = 0;
	while(vec.size() > 0){
		pop_heap(vec.begin(),vec.end(),Comp()); //Note to self pop_heap takes the most priority element and keeps it at the end of the container. The remaining part (v.begin(),v.end()-1) is a heap
		temp = vec[vec.end()-vec.begin()-1];
		vec.erase(vec.end()-1);
		cout << temp.index << endl;
		vis[temp.index] = 1;
		for (int i=0;i<data[temp.index].size();i++){
			if (vis[data[temp.index][i]] == 0 && dis[data[temp.index][i]] > dis[temp.index] + weight[temp.index][i]){
				node temp1;
				dis[data[temp.index][i]] = dis[temp.index] + weight[temp.index][i];
				temp1.index = data[temp.index][i];
				temp1.weight = dis[data[temp.index][i]];
				vec.push_back(temp1);
				push_heap(vec.begin(),vec.end(),Comp());//Note to self push_heap assumes your container(v.begin(),v.end()) is already a heap and then it heapifies the added element (v.end()+1)
			}
		}
	}
	cout << "Minimum distances are ";
	for (int i=1;i<=v;i++){
		cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}