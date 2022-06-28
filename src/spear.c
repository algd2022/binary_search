#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m, int *A){
  int sum = 0;
  int i;
  for (i = 0; i < n; i++){
    sum += A[i] / m;
  }
  return sum < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while ( ub - lb > 1) {
    int mid = ( lb + ub ) / 2;
    if( p ( mid , A )){
      ub = mid ;
    }
    else {
      lb = mid ;
    }
  }
  printf ( "%d\n " , lb );
  return 0;
  
}
