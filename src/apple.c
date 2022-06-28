#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  if (m <= k) return 1;
  else return 0;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 1;
  ub = 1000000000;
  /*bsearch*/
  while (ub - lb > 1){
    int mid = (lb + ub) / 2;
    int sum = 0;
    /*sum += ceil(A[i]/mid)*/
    for(i = 0; i < n; i++) sum += (A[i] + mid - 1) / mid;
    if(p(sum)) ub = mid;
    else lb = mid;
  }
  /*result*/
  printf("%d\n", ub);

  return 0;
}
