#include <stdio.h>

int n;
int k;
int A[100000];
int mid=0; //global変数
int j=0;
int tree_num = 0;
int tmp=0;

int tree_judge(int m){
  for(j=0;j<n;j++)
  {
    if(A[j] >= m)
    { 
      tree_num += A[j] / m; //切り上げないように
    }
  }
  tmp=tree_num;
  tree_num=0;
  
  //printf("mid=%d,tmp=%d\n",m,tmp);
  if(tmp < k)
  {
      return 1;
  }
  else
  {
      return 0;    
  }
  //printf("tree_num=%d\n",tree_num);
}


int main(void){
  int i,max,ub,lb,sum_length = 0;  
  scanf("%d%d", &n, &k);
  
  for(i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
    sum_length = sum_length + A[i];
    //printf("%d\n",A[i]);
    
  }
  
  ub = sum_length / k; 
  lb = 0;
  
  
  while(ub - lb > 1)
  {
    mid = (ub + lb) / 2;
    //printf("mid=%d\n",mid);
    if(tree_judge(mid) == 1)
    {
      ub = mid;
      //printf("lb=%d,ub=%d\n",lb,ub);
    }
    if(tree_judge(mid) == 0) 
    {
      lb = mid;
     // printf("lb=%d,ub=%d\n",lb,ub);
    }
    if(k==0)
    {
      lb = 0;
    }
  }
  //printf("%d\n",lb);
  printf("%d",lb);
  return 0;
}
