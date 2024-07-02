#include<bits/stdc++.h>
using namespace std;
int cnvrt(string aa)
{
	int ret=0;
	for(int i=0;i<aa.length();i++)
	{
		ret*=10;
		ret+=aa[i]-'0';
	}
	return ret;
}
int main()
{
	int poiuytrewq;
	cin>>poiuytrewq;
	for(int qwertyuiop=0;qwertyuiop<poiuytrewq;qwertyuiop++)
	{
		int n;
		cin>>n;
		vector<string> a;
		for(int i=0;i<n;i++)
		{
			string aa;
			cin>>aa;
			a.push_back(aa);
		}
		vector<int> b;
		string ans="yes\n";
		for(int i=n-2;i>=0;i--)
		{
			if(cnvrt(a[i])>cnvrt(a[i+1]))
			{
				string k=a[i];
				for(int j=0;j<k.size()-1;j++)
				{
					string temp="";
					temp+=k[j];
					string tempp="";
					tempp+=k[j+1];
					if(cnvrt(temp)>cnvrt(tempp))
					{
						ans="no\n";
					}
				}
				string temppp="";
				temppp=k[k.size()-1];
				if(cnvrt(temppp)>cnvrt(a[i+1]))
				{
					ans="no\n";
				}
				a[i]=a[i][0];
			}
		}
		/*for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<"\n___________\n";*/
		cout<<ans;
	}
}
