/*
https://www.interviewbit.com/problems/excel-column-number/

Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
*/

int Solution::titleToNumber(string A) {
    int n=A.size()-1;
    int res=0;
    for(int i=n;i>=0;i--)
    {
        res+=(A[i]-'A'+1)*pow(26,n-i);
    }
    return res;
}
