#include<bits/stdc++.h>
using namespace std;
vector<long long> dist[300000];
vector<long long> a[300000];
long long n;
bool visitt[300000]={false};
long long maxd=0;
void dfs(long long ii,long long d)
{
	if(visitt[ii])
	{
		return;
	}
	visitt[ii]=true;
	maxd=max(maxd,d);
	dist[d].push_back(ii);
	for(long long i=0;i<a[ii].size();i++)
	{
		dfs(a[ii][i],d+1);
	}
}
int main()
{
	long long tttttt;
	cin>>tttttt;
	for(long long ttttt=0;ttttt<tttttt;ttttt++)
	{
		cin>>n;
		vector<long long> p;
		p.push_back(0);
		maxd=0;
		for(long long i=0;i<n;i++)
		{
			a[i].clear();
			dist[i].clear();
			visitt[i]=false;
		}
		for(long long i=0;i<n-1;i++)
		{
			long long aa;
			cin>>aa;
			aa--;
			p.push_back(aa);
			a[aa].push_back(i+1);
			a[i+1].push_back(aa);
		}
		dfs(0,0);
		long long dp[300005]={0};
		long long prev=0;
		for(long long i=0;i<maxd+1;i++)
		{
			if(i==0)
			{
				dp[0]=1;
				prev=1;
			}
			else if(i==1)
			{
				for(long long j=0;j<dist[i].size();j++)
				{
					dp[dist[i][j]]=1;
				}
				prev=dist[i].size()%998244353;
			}
			else
			{
				long long newprev=0;
				for(long long j=0;j<dist[i].size();j++)
				{
					dp[dist[i][j]]=(prev%998244353-dp[p[dist[i][j]]]%998244353)%998244353;
					newprev+=(prev%998244353-dp[p[dist[i][j]]]%998244353)%998244353;
					newprev%=998244353;
				}
				prev=newprev%998244353;
			}
		}
		long long ans=0;
		for(long long i=0;i<n;i++)
		{
			//cout<<dp[i];
			if(dp[i]<0)
			{
				dp[i]+=998244353;
			}
			ans+=dp[i]%998244353;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
}
