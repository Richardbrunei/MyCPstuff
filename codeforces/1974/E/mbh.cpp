#include<bits/stdc++.h>
using namespace std;
long long mnbvcxz;
long long m,x;
long long dp[100005]={0};
int main()
{
	cin>>mnbvcxz;
	for(long long qwertyuiop=0;qwertyuiop<mnbvcxz;qwertyuiop++)
	{
		cin>>m>>x;
		long long sumh=0;
		for(long long j=0;j<100005;j++)
		{
			dp[j]=-99999999;
		}
		vector<long long> cc;
		vector<long long> hh;
		for(long long i=0;i<m;i++)
		{
			long long ccc,hhh;
			cin>>ccc>>hhh;
			sumh+=hhh;
			cc.push_back(ccc);
			hh.push_back(hhh);
		}
		dp[0]=0;
		for(long long i=0;i<m;i++)
		{
			long long c,h;
			c=cc[i];
			h=hh[i];
			/*cout<<"|";
			for(long long i=0;i<10;i++)
			{
				cout<<dp[i]<<" ";
			}
			cout<<endl;*/
			for(long long j=sumh+3;j>=0;j--)
			{
				if(j>=h&&dp[j-h]>=c)
				{
					dp[j]=max(dp[j]+x,dp[j-h]+x-c);
				}
				else if(dp[j]!=-99999999)
				{
					dp[j]+=x;
				}
			}
		}
		/*cout<<"|";
		for(long long i=0;i<10;i++)
		{
			cout<<dp[i]<<" ";
		}
		cout<<endl;*/
		for(long long i=sumh+3;i>=0;i--)
		{
			if(dp[i]>=0)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}
