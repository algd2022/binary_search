#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m, int k, int *A){
  int i;
  int save = m;
  int p = 0;
  for (i = 0; i < n; i++){
    if (m - A[i]>= 0){
      m -= A[i];
    }
    else{
      m = save-A[i];
      p++;
    }
  }
  
  return p <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int max;
  max = A[0];
  for (i = 0; i < n; i++) {
      if (A[i] > max) {
          max = A[i];
      }
  }
  lb = max;
  ub = 1000000001; 
  while ( ub - lb > 1) {
    int mid = ( lb + ub ) / 2;
    if( p ( mid , k , A )){
      ub = mid ;
    }
    else {
    lb = mid ;
    }
  }
  printf ( "%d\n " , ub );
  return 0;
}
