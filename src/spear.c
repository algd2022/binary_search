#include <stdio.h>

int n;
int k;
int A[100000];

int p(int cutlong){
  int spearsum = 0,i;
  for(i = 0;i < n;i++){
    spearsum += A[i]/cutlong;
  }
  return spearsum >= k;
}

int main(){
  int i, lb, ub;
  printf("n? k?\n");
  scanf("%d%d", &n, &k);
  printf("A[i]?\n");
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) lb = mid;
    else ub = mid;
  }
  printf("x = %d\n",lb);
  return 0;
}