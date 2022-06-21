#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[],int x){ //長さxの槍をk本作れるかどうか
  int sum = 0;
  for(int i=0;n>i;i++){
    sum += A[i]/x;
  }
  return sum>=k ? 0 : 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9;
  while (ub-lb>1){
    int mid = (lb+ub)/2;
    //printf("%d %d\n",ub,lb);
    if(p(A, mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n",lb);
  return 0;
}
