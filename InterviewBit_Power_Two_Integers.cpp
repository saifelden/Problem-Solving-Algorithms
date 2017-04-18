/*
https://www.interviewbit.com/problems/power-of-two-integers/
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 
*/
#include <iostream>
#include <cmath>
using namespace std;
bool is_factorized(int A,int b)
{
    unsigned long long tmp;
  while(A>1)
  {
    tmp=b;
    while(tmp<=A)
    {
        //cout<<tmp<<endl;
        if(A%tmp!=0)
         return false;
      tmp*=tmp;
    }
    if(A%(int)sqrt(tmp)==0)
     A/=sqrt(tmp);
   else
     return false;
  }
  return true;
}
bool isPower(int A) {
    int s=sqrt(A);
    
    for(int i=2;i<=s;i++)
    {
      
        if(A%i==0)
        {
         if(is_factorized(A,i))
           return true;
        }
    }
    return false;
}
int main()
{
   int n;
   cin>>n;
   cout<<isPower(n)<<endl;
}