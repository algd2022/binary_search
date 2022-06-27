#include <stdio.h>

int n;
int k;
int A[100000];
int mid=0; //global変数
int j=0;
int bag_num=0;

int bag_judge(int m){
  for(j=0;j<n;j++)
  {
    scanf("%d", &A[j]);
    bag_num += (A[j]+ m - 1) / m; //mがリンゴを何個入れるか
    //printf("%d\n",A[j]);
  }
  if(bag_num <= k)
  {
      return  1;    
  }
  else
  {
      return  0; 
  }
}


int main(void){
  int i,max,ub,lb;  
  scanf("%d%d", &n, &k);
  
  for(i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
    if(max < A[i])
    {
      max = A[i];
      ub = A[i];
    }
  }
  
  lb = 0; //maxは上で定義してある
  
  
  while(ub - lb > 1)
  {
    mid = (ub + lb)/2;
    if(bag_judge(mid) == 1)
    {
      ub = mid;
    }
    else if(bag_judge(mid) == 0) 
    {
      lb = mid;
    }
  printf("%d\n",lb);
  }
  return 0;
}