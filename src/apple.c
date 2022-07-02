#include <stdio.h>

int n;
int k;
int A[100000];

int p(int mid){
  int sum = 0;
  /*sum += ceil(A[i]/mid)*/
  for(int i = 0; i < n; i++) sum += (A[i] + mid - 1) / mid;
  if (sum <= k) return 1;
  else return 0;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //値の修正
  ub = 1000000000;
  /*bsearch*/
  while (ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  /*result*/
  printf("%d\n", ub);

  return 0;
}
