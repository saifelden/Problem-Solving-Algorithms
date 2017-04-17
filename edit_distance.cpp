#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector< vector< int > > dp;
int edit_distance(string s1,string s2,int iter1,int iter2)
{
   if(iter1==s1.size()&&iter2==s2.size())
   	return 0;
   if(iter1==s1.size())
   	 return s2.size()-iter2;
      if(iter2==s2.size())
   	 return s1.size()-iter1;
   	if(dp[iter1][iter2]!=-1)
   		return dp[iter1][iter2];
    int sol1=100000,sol2=100000,sol3=100000,sol4=100000;
   if(s1[iter1]==s2[iter2])
   	  sol1=edit_distance(s1,s2,iter1+1,iter2+1);
   sol2=edit_distance(s1,s2,iter1+1,iter2+1)+1;
   sol3=edit_distance(s1,s2,iter1+1,iter2)+1;
   sol4=edit_distance(s1,s2,iter1,iter2+1)+1;
   dp[iter1][iter2]=min(min(sol1,sol2),min(sol3,sol4));
   return dp[iter1][iter2];
}
 int main()
 {
 	string s1,s2;
 	cin>>s1;
 	cin>>s2;
    dp.resize(s1.size());
    for(int i=0;i<s1.size();i++)
    {	vector<int> tmp(s2.size(),-1);
    	dp[i]=tmp;
    }
    int res=edit_distance(s1,s2,0,0);
    cout<<"the result is"<<res<<endl;
 }