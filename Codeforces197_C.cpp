#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector< vector< short > > dp(5000,vector< short >(5000,-1));
vector<short> best_res;
bool doit(vector<short>& w,int n,vector<short> out,int left,int right,bool l,int last)
{
    int m=w.size();
    bool curr_sol=false;
    
    if(n==0)
    {
              best_res=out;
              return true;
    }
    //cout<<left<<" "<<right<<" "<<l<<endl;
    if(dp[left][right]!=-1)
    	return dp[left][right];
    for(int i=0;i<m;i++)
    {
    	if(i==last)
    		 continue;
    	vector<short> tmp(out);
       tmp.push_back(w[i]);
       if(l)
       {	if(left+w[i]>right)
             curr_sol=doit(w,n-1,tmp,left+w[i],right,not(l),i);
        }
       else
       	 {if(right+w[i]>left)
          curr_sol= doit(w,n-1,tmp,left,right+w[i],not(l),i);
       }
     if(curr_sol)
     {
     	dp[left][right]=curr_sol;
     	return true;
     }
    }
    //cout<<left<<" "<<right<<" "<<l<<endl;
    dp[left][right]=curr_sol;
    return false;
}
int main()
{
  string s;
  cin>>s;
  int n;
  cin>>n;
  vector<short> w;
  for(int i=0;i<s.size();i++)
    if(s[i]=='1')
  	 w.push_back(i+1);
   vector<short> out;
  bool res=doit(w,n,out,0,0,true,-1);
  if(res)
  {
  	cout<<"YES"<<endl;
  	for(int i=0;i<best_res.size();i++)
    {
    	cout<<best_res[i]<<" ";
    }
    cout<<endl;
  }
  else
  	cout<<"NO"<<endl;

  
}