#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long qpwoei;
	cin>>qpwoei;
	for(long long pqowie=0;pqowie<qpwoei;pqowie++)
	{
		long long n,m,k;
		cin>>n>>m>>k;
		vector<long long> a;
		for(long long i=0;i<n;i++)
		{
			long long aa;
			cin>>aa;
			a.push_back(aa);
		}
		sort(a.begin(),a.end());
		long long ans=0;
		long long add=0;
		for(long long i=0;i<n;i++)
		{
			long long num=min(k,m);
			ans+=num*(a[i]+add);
			add+=num;
			k-=num;
		}
		cout<<ans<<endl;
	}
}
