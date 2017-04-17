#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int m,s;
	cin>>m;
	cin>>s;
	string big(m,'0'),small(m,'0');
	int tmp=s;
	if(9*m<s||(s==0&&m>1))
	{
		cout<<"-1 -1";
		return 0;
	}

	if(s==0&&m==1)
	{
		cout<<"0 0";
		return 0;
	}
	for(int i=0;i<m;i++)

	{
		if(tmp>=9)
		{
			big[i]=('0'+9);
	        tmp-=9;
		}
		else
		{
			big[i]=('0'+tmp);
			break; 
		}
	}
	small[0]='1';
    //cout<<endl<<small<<" "<<big<<endl;
	tmp=s;
	tmp--;
	for(int i=m-1;i>=0;i--)
	{
		if(tmp>=9)
		{
			small[i]+=9;
	        tmp-=9;
		}
		else
		{
			small[i]+=tmp;
			break; 
		}
	}
	cout<<small<<" "<<big;
	return 0;
}