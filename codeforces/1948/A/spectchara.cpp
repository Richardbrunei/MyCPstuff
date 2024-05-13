#include<bits/stdc++.h>
using namespace std;
int main()
{
	int qwertyuiopmnbvcxz;
	cin>>qwertyuiopmnbvcxz;
	for(int zxcvbnmpoiuytrewq=0;zxcvbnmpoiuytrewq<qwertyuiopmnbvcxz;zxcvbnmpoiuytrewq++)
	{
		int n;
		cin>>n;
		if(n%2==1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			for(int i=0;i<n/2;i++)
			{
				cout<<"AAB";
			}
			cout<<endl;
		}
	}
}
