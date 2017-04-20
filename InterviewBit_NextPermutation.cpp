/*

https://www.interviewbit.com/problems/next-permutation/
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

 Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION
*/
void Solution::nextPermutation(vector<int> &A) {
int n=A.size();
if(n==1)
 return ;
int index=-1;
int next;
int tmp;
for(int i=n-1;i>0;i--)
{
    if(A[i-1]<A[i])
    {  index=i-1;
      next=-1;
     for(int j=i;j<n;j++)
    {
        if(A[j]>A[i-1]&&(next==-1||A[j]<A[next]))
         next=j;
    }
       tmp=A[i-1];
       A[i-1]=A[next];
       A[next]=tmp;
       int j=i;
       int k=n-1;
       while(k>j)
       {
           tmp=A[j];
           A[j]=A[k];
           A[k]=tmp;
           k--;
           j++;
       }
       break;
    }
}
if(index==-1)
{
    int j=0;
       int k=n-1;
       while(k>j)
       {
           int tmp=A[j];
           A[j]=A[k];
           A[k]=tmp;
           k--;
           j++;
       }
}
 
}
