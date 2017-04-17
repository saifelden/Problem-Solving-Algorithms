#include<iostream>
#include<vector>
using namespace std;
vector< vector< vector< int > > > dp;
int LCS(vector<int>& s1,vector<int>& s2,vector<int>& s3,int iter1,int iter2,int iter3)
{
	if(iter1==s1.size()||iter2==s2.size()||iter3==s3.size())
		return 0;
    if(dp[iter1][iter2][iter3]!=-1)
    	return dp[iter1][iter2][iter3];
    int sol1=0,sol2=0,sol3=0,sol4=0;
	if(s1[iter1]==s2[iter2]&&s2[iter2]==s3[iter3])
	   sol1=LCS(s1,s2,s3,iter1+1,iter2+1,iter3+1)+1;
	sol2=LCS(s1,s2,s3,iter1+1,iter2,iter3);
	sol3=LCS(s1,s2,s3,iter1,iter2+1,iter3);
	sol4=LCS(s1,s2,s3,iter1,iter2,iter3+1);
	dp[iter1][iter2][iter3] = max(max(sol1,sol2),max(sol3,sol4));
	return dp[iter1][iter2][iter3];
}
int main()
{
	int x,y,z;
 		cin>>x;
   vector<int> s1(x);
  
 for (int i = 0; i < x; ++i)
  {
  	cin>>s1[i];

  }	
  
  		cin>>y;

     vector<int> s2(y);
     for (int i = 0; i < y; ++i)
     {
     	cin>>s2[i];
     }
   cin>>z;

        vector<int> s3(z);
        for (int i = 0; i < z; ++i)
        {
        	cin>>s3[i];
        }
   vector<vector<vector<int> > > vec = vector<vector<vector<int> > >( x, vector<vector<int> >(y, vector<int>(z,-1)));
   dp=vec;
   int res=LCS(s1,s2,s3,0,0,0);
   cout<<"result is "<<res<<endl;
   return 0;
}