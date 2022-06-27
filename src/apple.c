#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int i,g = 0;
  for(i = 0; i < n; i++){
     g = g + (A[i] + x -1)/x; 
  }
  if(g <= k){
    return 1;
  }
  else{
    return 0;
  } 
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //lbの一つ右が最小値//
  ub = 1000000000; //右端は参照されうるのでxの最大値//
  while( ub - lb > 1){
    int mid = ( lb + ub ) / 2;
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
