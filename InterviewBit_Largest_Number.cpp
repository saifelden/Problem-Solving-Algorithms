/*
https://www.interviewbit.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
bool compare(string s1,string s2)
{
   if(s1.find(s2)!=std::string::npos||s2.find(s1)!=std::string::npos)
   {
      string ss1=s1+s2;
      string ss2=s2+s1;
      if(ss1>ss2)
        return false;
      else
        return true;
   }
   return (s1<s2);
}
string Solution::largestNumber(const vector<int> &A) {
vector<string> str;
for(int i=0;i<A.size();i++)
{
    str.push_back(to_string(A[i]));
}
sort(str.rbegin(),str.rend(),compare);
string bigstr="";
for(int i=0;i<str.size();i++)
{
    if(str[i]=="0")
      continue;
    bigstr+=str[i];
}
if(bigstr=="")
  return "0";
return bigstr;
}