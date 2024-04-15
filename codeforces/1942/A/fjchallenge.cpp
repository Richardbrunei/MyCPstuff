#include<bits/stdc++.h>
using namespace std;
int main()
{
	int asdf;
	cin>>asdf;
	for(int qwerty=0;qwerty<asdf;qwerty++)
	{
		int n,k;
		cin>>n>>k;
		if(n==k)
		{
			for(int i=0;i<n;i++)
			{
				cout<<"1 ";
			}
		}
		else if(k==1)
		{
			for(int i=0;i<n;i++)
			{
				cout<<i+1<<" ";
			}
		}
		else
		{
			cout<<"-1";
		}
		cout<<endl;
	}
}
