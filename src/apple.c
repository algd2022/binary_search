#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i, l;
  l = 0;
  for (i = 0; i < n; i++){
    l = l + (A[i] + m - 1) / m;
  }
  return (long long int) l <= k;
}

/* pの計算量はO(n) */

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
