#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tttt;
	cin>>tttt;
	for(int ttt=0;ttt<tttt;ttt++)
	{
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int psum[200005][2]={0};
		for(int i=0;i<n;i++)
		{
			psum[i+1][0]=psum[i][0]+(a[i]=='A');
			psum[i+1][1]=psum[i][1]+(b[i]=='A');
		}
		vector<vector<int> > dp(n+5,vector<int>(3));
		//int dp[100005][3]={0};
		dp[0][1]=(((a[0]=='A')+(b[0]=='A')+(a[1]=='A'))>1);
		dp[0][2]=(((b[0]=='A')+(a[0]=='A')+(b[1]=='A'))>1);
		dp[0][0]=0;
		dp[2][0]=((psum[3][0]-psum[0][0])>1)+((psum[3][1]-psum[0][1])>1);
		for(int i=0;i<n;i++)
		{
			if(i<n-3&&i%3==2)
			{
				dp[i+3][0]=max(dp[i+3][0],dp[i][0]+((psum[i+4][0]-psum[i+1][0])>1)+((psum[i+4][1]-psum[i+1][1])>1));
			}
			if(i<n-2&&i%3==2)
			{
				dp[i+1][1]=max(dp[i+1][1],dp[i][0]+(((b[i+1]=='A')+(a[i+1]=='A')+(a[i+2]=='A'))>1));
				dp[i+1][2]=max(dp[i+1][2],dp[i][0]+(((a[i+1]=='A')+(b[i+1]=='A')+(b[i+2]=='A'))>1));
			}
			if(i<n-2&&i%3==0)
			{
				dp[i+2][0]=max(dp[i+2][0],dp[i][2]+(((b[i+2]=='A')+(a[i+1]=='A')+(a[i+2]=='A'))>1));
				dp[i+2][0]=max(dp[i+2][0],dp[i][1]+(((a[i+2]=='A')+(b[i+1]=='A')+(b[i+2]=='A'))>1));
			}
			if(i<n-5&&i%3==0)
			{
				dp[i+3][1]=max(dp[i+3][1],dp[i][1]+((psum[i+5][0]-psum[i+2][0])>1)+((psum[i+4][1]-psum[i+1][1])>1));
				dp[i+3][2]=max(dp[i+3][2],dp[i][2]+((psum[i+5][1]-psum[i+2][1])>1)+((psum[i+4][0]-psum[i+1][0])>1));
			}
		}
		/*for(int i=0;i<3;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<dp[j][i]<<" ";
			}
			cout<<endl;
		}*/
		cout<<dp[n-1][0]<<endl;
	}
}
