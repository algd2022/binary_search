#include <stdio.h>

int n;
int k;
int A[100000];

int p(int maxwork){
  if(maxwork) return 1;
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = n;
  /*bsearch*/
  while (ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  /*result*/
  printf("%d\n", A[ub]);
  return 0;
  return 0;
}
