/*
https://www.interviewbit.com/problems/set-matrix-zeros/

Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
*/

void Solution::setZeroes(vector<vector<int> > &A) {
  int n=A.size();
  int m=A[0].size();
  vector<int> htn(n,0),htm(m,0);
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          if(!A[i][j])
          {
              htn[i]=1;
              htm[j]=1;
          }
      }
  }
   for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
           if(htn[i]==1||htm[j]==1)
            A[i][j]=0;
      }
      
  }
}
