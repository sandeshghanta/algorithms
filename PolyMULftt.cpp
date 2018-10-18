#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define endl '\n'
#define M_PI 3.14159265358979323846264338327950288
using namespace std;
typedef complex<double> cp;
#define MAXN 32768
void fft(vector<cp> &a,vector<cp>&b, cp w)
{
	int n=a.size();
	b.resize(n);
	if(n==1)
		b[0]=a[0];
	else
	{
		vector<cp> b1(n/2),b2(n/2);
		for(int i=0;i<n/2;++i)
		{
			b1[i]=a[2*i];
			b2[i]=a[2*i+1];
		}
		vector<cp> y1,y2;
		fft(b1,y1,w*w);
		fft(b2,y2,w*w);
		cp wn=cp(1,0);
		for(int i=0;i<n/2;++i)
		{
			b[i]=y1[i]+wn*y2[i];
			b[i+n/2]=y1[i]-wn*y2[i];
			wn=wn*w;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<cp> p1(MAXN,cp(0,0)),p2(MAXN,cp(0,0)),p3,p4,v;
		for(int i=0;i<=n;++i)
		{
			int x;
			cin>>x;
			p1[i]+=cp(x,0);
		}
		for(int i=0;i<=n;++i)
		{
			int x;
			cin>>x;
			p2[i]+=cp(x,0);
		}
		double alpha=(double) 2*M_PI/(double) MAXN;
		cp w=cp(cos(alpha),sin(alpha));
		fft(p1,p3,w);
		fft(p2,p4,w);
		for(int i=0;i<MAXN;++i)
			p3[i]=p3[i]*p4[i];
		fft(p3,v,cp(1,0)/w);
		for(int i=0;i<=2*n;++i)
		{
			ll x= round( v[i].real() / (double ) MAXN );
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
