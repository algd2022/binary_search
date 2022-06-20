#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int j;
  int sum = 0;
  for(j = 0;j < n;j++){
    if(A[j] % m == 0){
      sum += A[j]/m;
    }
    else{
      sum += A[j]/m + 1;
    }
  }
  return sum <= k;
}

int main(){
  int i, lb, ub;
  lb = 0;
  ub = 1000000000;

  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while ( ub - lb > 1) {
    int mid = ( lb + ub ) / 2;
    if(p ( mid )){
      ub = mid ;
    }
  else {
    lb = mid ;
  }
  }
  printf("%d\n", ub);

  return 0;
}
