/*
https://www.interviewbit.com/problems/grid-unique-paths/

A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).



The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
*/
vector<vector<int>> dp;
int doit(int h,int w,int x,int y)
{
    int sol1=0,sol2=0;
    if(x==h-1&&y==w-1)
     return 1;
    if(dp[x][y]!=-1)
      return dp[x][y];
    if(x<h-1)
     sol1=doit(h,w,x+1,y);
    if(y<w-1)
     sol2=doit(h,w,x,y+1);
     dp[x][y]=sol1+sol2;
     return dp[x][y];
 }
int Solution::uniquePaths(int A, int B) {
  vector<vector<int>> vec(A,vector<int>(B,-1));
  dp=vec;
  return doit(A,B,0,0);
}