#include<bits/stdc++.h>

using namespace std;
int v,e;
vector<int>data[1000];
int vis[1000];
string convert(int s){
	string ans = "";
	stack<char>st;
	while (s > 0){
		st.push((char)(s%10 + 48));
		s = s/10;
	}
	while (st.size() > 0){
		ans = ans + st.top();
		st.pop();
	}
	return ans;
}
void dfs(int source,int end,string path){
	path = path + " " + convert(source);
	vis[source] = 1;
	if (source == end){
		cout << path << endl;
		vis[source] = 0;
		return;
	}
	for (int i=0;i<data[source].size();i++){
		if (vis[data[source][i]] == 0){
			dfs(data[source][i],end,path);
		}
	}
	vis[source] = 0;
}
int main(){
	int i,source,end,a,b;
	string path = "";
	cout << "Enter number of vertices ";
	cin >> v;
	cout << "Enter number of edges ";
	cin >> e;
	cout << "Enter the edges " << endl;
	for (i=0;i<e;i++){
		cin >> a >> b;
		data[a].push_back(b);
		data[b].push_back(a);
	}
	for (i=1;i<=v;i++){
		vis[i] = 0;
	}
	cout << "Enter the source ";
	cin >> source;
	cout << "Enter the destination ";
	cin >> end;
	cout << "All the possible paths are " << endl;
	dfs(source,end,path);
	return 0;
}
	
