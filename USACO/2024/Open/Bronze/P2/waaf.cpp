#include<bits/stdc++.h>
using namespace std;
vector<int> x;
vector<int> y;
int n,p;
int peri=0;
int dist[1005][1005]={0};
int main()
{
	cin>>p>>n;
	for(int i=0;i<n;i++)
	{
		int aa,bb;
		cin>>aa>>bb;
		x.push_back(aa);
		y.push_back(bb);
	}
	for(int i=0;i<n;i++)
	{
		int k=(i+1)%n;
		peri+=abs(x[k]-x[i])+abs(y[k]-y[i]);
	}
	for(int i=0;i<n;i++)
	{
		int a=x[i];
		int b=y[i];
		int k=(i+1)%n;
		int c=x[k];
		int d=y[k];
		if(b==d)
		{
			//cout<<"a";
			if(c>a)
			{
				//cout<<"b";
				for(int j=a+1;j<=c;j++)
				{
					//cout<<"c";
					dist[j][b]=dist[j-1][b]+1;
				}
			}
			else
			{
				for(int j=a-1;j>=c;j--)
				{
					dist[j][b]=dist[j+1][b]+1;
				}
			}
		}
		if(a==c)
		{
			if(d>b)
			{
				for(int j=b+1;j<=d;j++)
				{
					dist[a][j]=dist[a][j-1]+1;
				}
			}
			else
			{
				for(int j=b-1;j>=d;j--)
				{
					dist[a][j]=dist[a][j+1]+1;
				}
			}
		}
	}
	/*for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	for(int i=0;i<p;i++)
	{
		int aa,bb,cc,dd;
		cin>>aa>>bb>>cc>>dd;
		cout<<min(abs(dist[aa][bb]-dist[cc][dd]),peri-abs(dist[aa][bb]-dist[cc][dd]))<<endl;
	}
}
