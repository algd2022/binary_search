#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x)
{
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=(A[i]+x-1)/x;
  } 

  return k>=sum;
} 

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb=0;
  ub=1e9;  /*n人全員が10^9個をとり、k=nの時、袋に入るリンゴの数は最大になり、10^9ことなる*/
  
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(p(mid)){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }

  printf("%d\n",ub);
  return 0;
}
