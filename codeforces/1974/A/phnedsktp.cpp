#include<bits/stdc++.h>
using namespace std;
int main()
{
	int qpwoeiruty;
	cin>>qpwoeiruty;
	for(int alskdjfhg=0;alskdjfhg<qpwoeiruty;alskdjfhg++)
	{
		int a,b;
		cin>>a>>b;
		int ans=0;
		if(b%2==0)
		{
			ans=b/2;
			a-=ans*7;
			if(a>0)
			{
				ans+=a/15+(a%15>0);
			}
		}
		else
		{
			ans=b/2;
			a-=ans*7;
			a-=11;
			if(a>0)
			{
				ans+=a/15+(a%15>0);
			}
			ans++;
		}
		cout<<ans<<endl;
	}
}
