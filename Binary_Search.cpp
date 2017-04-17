#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool Binary_Search(vector<int>& arr,int Begin,int End,int x)
{
	if(Begin>End)
		return false;
   
 
	int mid=(Begin+End)/2;

	
		
	if(arr[mid] < x)
		return Binary_Search(arr,mid+1,End,x);
	else if(arr[mid] > x)
		return Binary_Search(arr,Begin,mid-1,x);
	return true;
}
int main()
{
	int size,num;
	cin>>size;
	cin>>num;
	vector<int> arr(size);
	for(int i=0;i<size;i++)
	   cin>>arr[i];
    sort(arr.begin(),arr.end());
    bool is_found=Binary_Search(arr,0,arr.size()-1,num);
   if(is_found)
     cout<<endl<<"the number "<<num<<" is found"<<endl;
   else
  	 cout<<endl<<"the number "<<num<<" is not found"<<endl;
}