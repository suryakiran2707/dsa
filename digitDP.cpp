#include<bits/stdc++.h>
using namespace std;
class digitDP
{
	public:
    long long dp[20][2][10];
    string a;
	digitDP(long long num)
	{
		a=to_string(num);
		memset(dp,-1,sizeof(dp));
	}	
	long long finddp(int ind,int tig,int prev)
	{
		if(ind==a.size())
		{
			return 1;
		}
		long long ans=0;
		if(dp[ind][tig][prev]!=-1)
		return dp[ind][tig][prev];
		if(tig==0)
		{
			for(int i=0;i<=9;i++)
			{
				if(i==0 && prev==-1)
				{
					ans=ans+finddp(ind+1,tig,-1);
				}
				else if(i!=prev)
				{
					ans=ans+finddp(ind+1,tig,i);
				}
			}
		}
		else
		{
			int y=a[ind]-'0';
			for(int i=0;i<y;i++)
			{
				if(i==0 && prev==-1)
				{
					ans=ans+finddp(ind+1,0,-1);
				}
				else if(i!=prev)
				{
					ans=ans+finddp(ind+1,0,i);
				}
			}
			if(y!=prev)
			{
				ans=ans+finddp(ind+1,1,y);
			}
		}
		dp[ind][tig][prev]=ans;
		return ans;
	}
};
