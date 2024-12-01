#include<bits/stdc++.h>
using namespace std;
int main()
{
	int mnbvcxz;
	cin>>mnbvcxz;
	for(int qwertyuiop=0;qwertyuiop<mnbvcxz;qwertyuiop++)
	{
		int n;
		string s;
		cin>>n>>s;
		set<char> ss;
		for(int i=0;i<n;i++)
		{
			ss.insert(s[i]);
		}
		set<char>::iterator it;
		string r="";
		int idx[27]={0};
		int ii=0;
		for(it=ss.begin();it!=ss.end();it++)
		{
			r+=(*it);
			idx[(*it)-'a']=ii;
			ii++;
		}
		string ans="";
		for(int i=0;i<n;i++)
		{
			ans+=r[r.length()-idx[s[i]-'a']-1];
		}
		cout<<ans<<endl;
	}
}
