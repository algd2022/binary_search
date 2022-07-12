#include <stdio.h>

int n;
int k;
int A[100000];
int apple(int x){//if storage of bag=x
  int sub_k=k,j;
  for(j=0;j<n;j++){
    sub_k-=(A[j]+x-1)/x;//round up A[j]/x
  }
  if(sub_k>=0){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  int i, lb, ub,mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb=0;
  ub=1000000000;
  while((ub-lb)>1){
    mid=(lb+ub)/2;
    if(apple(mid)==1){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
