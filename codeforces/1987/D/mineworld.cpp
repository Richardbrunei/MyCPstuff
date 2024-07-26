#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main()
{
	int mnbvcxz;
	cin>>mnbvcxz;
	for(int zxcvbnm=0;zxcvbnm<mnbvcxz;zxcvbnm++)
	{
		int n;
		cin>>n;
		int a[5005]={0};
		for(int i=0;i<n;i++)
		{
			int aa;
			cin>>aa;
			a[aa]++;
		}
		priority_queue<pair<int,pii> > pq;
		int t=1;
		int cnt=0;
		//bool visit[5005]={false};
		//int last;
		/*for(int i=0;i<n+3;i++)
		{
			cout<<a[i]<<"|";
		}
		cout<<endl;*/
		for(int i=0;i<n+3;i++)
		{
			
			if(a[i]!=0)
			{
				cnt++;
				if(a[i]<=cnt-t)
				{
					//cout<<"&"<<i<<" "<<cnt<<endl;
					pq.push(make_pair(a[i],pii(t,i)));
					t+=a[i]+1;
				}
				else if(!pq.empty())
				{
					//cout<<"k";
					pii tp=pq.top().second;
					//cout<<"@"<<tp.second<<" "<<tp.first<<"}";
					if(a[i]<cnt-tp.first)
					{
						if(a[i]<a[tp.second])
						{
							//cout<<"#"<<i<<" "<<cnt<<" "<<a[tp.second]<<endl;
							pq.pop();
							t-=a[tp.second]+1;
							pq.push(make_pair(a[i],pii(t,i)));
							t+=a[i]+1;
						}
					}
				}
				//cout<<"!"<<t<<endl;
			}
		}
		//cout<<pq.size()<<" "<<t<<endl;
		cout/*<<"||||||||||||||"*/<<cnt-pq.size()<<endl;
	}
}
