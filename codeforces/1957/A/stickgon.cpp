#include<bits/stdc++.h>
using namespace std;
int main()
{
	int qwertyuiop;
	cin>>qwertyuiop;
	for(int asdfghjkl=0;asdfghjkl<qwertyuiop;asdfghjkl++)
	{
		int n;
		cin>>n;
		int a[101]={0};
		for(int i=0;i<n;i++)
		{
			int aa;
			cin>>aa;
			a[aa]++;
		}
		int ans=0;
		for(int i=0;i<101;i++)
		{
			ans+=a[i]/3;
		}
		cout<<ans<<endl;
	}
}
