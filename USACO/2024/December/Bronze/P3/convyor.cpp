#include<bits/stdc++.h>
using namespace std;
bool visted[1003][1003]={false};
bool a[1003][1003][4]={false};
int movex[4]={-1,1,0,0};
int movey[4]={0,0,-1,1};
int ans=0;
void dfs(int x,int y)
{
	if(visted[x][y])
	{
		return;
	}
	ans++;
	visted[x][y]=true;
	for(int i=0;i<4;i++)
	{
		if(a[x][y][i]/*&&!visted[x+movex[i]][y+movey[i]]*/)
		{
			dfs(x+movex[i],y+movey[i]);
		}
	}
}
int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);*/
	int n,q;
	cin>>n>>q;
	char og[1003][1003];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			og[i][j]='?';
		}
	}
	vector<int> qa;
	vector<int> qb;
	vector<char> qc;
	for(int i=0;i<q;i++)
	{
		int aa,bb;
		char cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		qa.push_back(aa);
		qb.push_back(bb);
		qc.push_back(cc);
		og[aa][bb]=cc;
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<og[i]<<endl;
	}*/
	string last[1004];
	last[0]="";
	last[n+1]="";
	for(int i=0;i<n+2;i++)
	{
		last[0]+='!';
		last[n+1]+='!';
	}
	for(int i=0;i<n;i++)
	{
		string k="!";
		for(int j=0;j<n;j++)
		{
			k+=og[i][j];
		}
		k+='!';
		last[i+1]=k;
	}
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<n+2;j++)
		{
			if(i>0)
			{
				if(last[i-1][j]=='!'||last[i-1][j]=='?'||last[i-1][j]=='D')
				{
					a[i][j][0]=true;
				}
				/*else
				{
					a[i][j][0]=false;
				}*/
			}
			if(i<n+1)
			{
				if(last[i+1][j]=='!'||last[i+1][j]=='?'||last[i+1][j]=='U')
				{
					a[i][j][1]=true;
				}
				/*else
				{
					a[i][j][1]=false;
				}*/
			}
			if(j>0)
			{
				if(last[i][j-1]=='!'||last[i][j-1]=='?'||last[i][j-1]=='R')
				{
					a[i][j][2]=true;
				}
				/*else
				{
					a[i][j][2]=false;
				}*/
			}
			if(j<n+1)
			{
				if(last[i][j+1]=='!'||last[i][j+1]=='?'||last[i][j+1]=='L')
				{
					a[i][j][3]=true;
				}
				/*else
				{
					a[i][j][3]=false;
				}*/
			}
		}
	}
	dfs(0,0);
	/*for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<n+2;j++)
		{
			cout<<visted[i][j];
		}
		cout<<endl;
	}*/
	int area=(n+2)*(n+2);
	vector<int> results;
	results.push_back(area-ans);
	for(int i=q-1;i>=0;i--)
	{
		//cout<<qa[i]<<" "<<qb[i];
		if(visted[qa[i]][qb[i]+1]||visted[qa[i]+1][qb[i]]||visted[qa[i]+2][qb[i]+1]||visted[qa[i]+1][qb[i]+2])
		{
			last[qa[i]+1][qb[i]+1]='#';
			//cout<<"!";
			dfs(qa[i]+1,qb[i]+1);
			
		}
		else
		{
			last[qa[i]+1][qb[i]+1]='*';
			a[qa[i]][qb[i]+1][1]=true;
			a[qa[i]+1][qb[i]][3]=true;
			a[qa[i]+1][qb[i]+2][2]=true;
			a[qa[i]+2][qb[i]+1][0]=true;
		}
		results.push_back(area-ans);
		/*cout<<"_________________\n"<<qa[i]+1<<" "<<qb[i]+1<<endl;
		for(int i=0;i<n+2;i++)
		{
			for(int j=0;j<n+2;j++)
			{
				cout<<visted[i][j];
			}
			cout<<endl;
		}*/
		//cout<<endl;
	}
	for(int i=results.size()-2;i>=0;i--)
	{
		cout<<results[i]<<endl;
	}
}
