#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long ttttttt;
	cin>>ttttttt;
	for(long long tttttt=0;tttttt<ttttttt;tttttt++)
	{
		long long n,m;
		cin>>n>>m;
		vector<long long> a;
		vector<long long> b;
		long long skil=0;
		for(long long i=0;i<n+m+1;i++)
		{
			long long aa;
			cin>>aa;
			a.push_back(aa);
		}
		for(long long i=0;i<n+m+1;i++)
		{
			long long aa;
			cin>>aa;
			b.push_back(aa);
		}
		long long nn=n;
		long long mm=m;
		long long last;
		for(long long i=0;i<n+m+1;i++)
		{
			if(n==0)
			{
				skil+=b[i];
				continue;
			}
			if(m==0)
			{
				skil+=a[i];
				continue;
			}
			if((nn==0&&a[i]>b[i])||(mm==0&&b[i]>a[i]))
			{
				last=i;
				for(long long j=i;j<n+m+1;j++)
				{
					if(a[i]>b[i])
					{
						skil+=b[j];
					}
					else
					{
						skil+=a[j];
					}
				}
				break;
			}
			else
			{
				skil+=max(a[i],b[i]);
				nn-=(a[i]>b[i]);
				mm-=(b[i]>a[i]);
			}
		}
		//cout<<skil<<endl;
		//cout<<"||||||||||||||||||||||||||||||||||";
		for(long long i=0;i<n+m+1;i++)
		{
			if(n==0)
			{
				cout<<skil-b[i]<<" ";
				continue;
			}
			if(m==0)
			{
				cout<<skil-a[i]<<" ";
				continue;
			}
			if(i>=last)
			{
				if(a[last]>b[last])
				{
					cout<<skil-b[i]<<" ";
				}
				else
				{
					cout<<skil-a[i]<<" ";
				}
			}
			else
			{
				if(a[last]>b[last])
				{
					//cout<<"A";
					if(a[i]>b[i])
					{
						cout<<skil-a[i]-b[last]+a[last]<<" ";
					}
					else
					{
						cout<<skil-b[i]<<" ";
					}
				}
				else
				{
					//cout<<"B";
					if(b[i]>a[i])
					{
						/*for(long long l=0;l<n+m+1;l++)
						{
							cout<<a[l]<<" "<<b[l]<<endl;
						}
						cout<<a[last]<<endl;*/
						//cout<<skil<<" "<<last<<" "<<i<<" "<<a[last]<<"b";
						cout<<skil-b[i]-a[last]+b[last]<<" ";
					}
					else
					{
						cout<<skil-a[i]<<" ";
					}
				}
			}
		}
		cout<<endl;
	}
}
