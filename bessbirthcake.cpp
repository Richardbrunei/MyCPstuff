#include<bits/stdc++.h>
using namespace std;
int main()
{
	int poiuytrewq;
	cin>>poiuytrewq;
	for(int zxcvbnm=0;zxcvbnm<poiuytrewq;zxcvbnm++)
	{
		int n,x,y,ans;
		cin>>n>>x>>y;
		ans=x-2;
		vector<int> a;
		for(int i=0;i<x;i++)
		{
			int aa;
			cin>>aa;
			a.push_back(aa);
		}
		sort(a.begin(),a.end());
		a.push_back(n+a[0]);
		for(int i=0;i<x;i++)
		{
			if(abs(a[i+1]-a[i])==2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
