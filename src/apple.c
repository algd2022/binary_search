#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1e9;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  while(ub - lb > 1){
    int mid =(lb + ub) / 2;
    int B = 0;
    for(i = 0; i < n; i++){
      B = B + (A[i] + mid - 1) / mid;
    }
    if(B <= k){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
