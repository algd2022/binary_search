#include <stdio.h>

int n;
int k;
int A[100000];

int p(x){
  unsigned int sum = 0;
  for(int i=0; i<n; i++) sum += A[i]/x;
  if(k<=sum) return 0; //もっと長くできる
  else return 1; //本数が足りない
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; 
  ub = 1000000001; 
  while(ub-lb>1){
    int mid = (lb + ub)/2;
    if(p(mid)) ub = mid;
    else lb = mid;
    //printf("ub:%d, mid:%d, lb:%d\n", ub, mid, lb);
  }
  printf("%d\n", lb);
  return 0;
}
