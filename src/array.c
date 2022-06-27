#include <stdio.h> //配列の二分探索

int n;
int k;
int A[100000];
int mid=0; //global変数

int main(){
  int i,ub, lb;  
  scanf("%d%d", &n, &k);
  
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  lb=0,ub=n;
  
  if(A[n-1]<k)
  {
    mid=n;    
  }

  while(ub - lb > 1)
  {
    mid = (ub + lb)/2;
    if(A[mid]>k)
    {
      ub = mid;
      //printf("%d\n",mid);
    }
    else 
    {
       lb = mid;
    }
    //printf("%d\n",mid);
  }
  printf("%d\n",ub);
  //printf("%d,%d",lb,ub);
  return 0;
}