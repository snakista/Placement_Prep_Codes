#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0)
#define ll long long int
#define forn(i,n) for(int i=0;i<int(n);i++)
#define pb push_back
vector<vector<pair<int,int> > > adj;
int n,m;
vector<int> d;
const int INF=1e9;
void dijakstra(int src)
{
	d=vector<int>(n+1);
	for(int i=0;i<=n;i++)
	{
		d[i]=INF;
	}
	d[src]=0;
	set<pair<int,int> > st;
	st.insert({d[src],src});
	while(!st.empty())
	{
		int v=st.begin()->second;
		st.erase(st.begin());
		for(int i=0;i<adj[v].size();i++)
		{
			int to=adj[v][i].first;
			int w=adj[v][i].second;
			if(d[to]>w+d[v])
			{
				set<pair<int,int> >::iterator it=st.find({d[to],to});
				if(it!=st.end())
				st.erase(it);
				d[to]=d[v]+w;
				st.insert({d[to],to});
			}
		}
	}
	for(int i=1;i<=n;i++)
	cout<<d[i]<<" ";
}
int main()
{
	fast;
	cin>>n>>m;
	adj=vector<vector<pair<int,int> > >(n+1);
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	dijakstra(1);
}
