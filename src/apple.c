#include <stdio.h>
int n;
int k;
int A[100000];

int Max(int *A){
  int M = 0;
  for(int i = 0; i < n; i++){
    if( M < A[i] ){
      M = A[i];
    }
  }
  return M;
}

int p(int x){
  int total = 0;
  for(int i = 0; i < n; i++){
    total += ( A[i] + x - 1 ) / x;
  }
  if (total <= k){
    return 1;
  }
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }


  lb = 0;
  ub = Max(A);
  while (ub-lb>1){
    int mid = (ub+lb)/2;
    if (p(mid)==1){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
