#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[],int x){
  int sum = 0;
  for(int i=0;n>i;i++){
    if(A[i]%x == 0){
      sum += A[i]/x;
    }else{
      sum += (A[i]/x) + 1;
    }
  }
  if(sum>k){
    return 0;
  }else{
    return 1;
  }
}

int main(){
  int i, lb, ub, max_a, total;
  max_a = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i]>max_a){
      max_a = A[i];
    }
  }
  lb = 0;
  ub = max_a;
  while (ub-lb>1){
    int mid = (lb+ub)/2;
    if(p(A, mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
