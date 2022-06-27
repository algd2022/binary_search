#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 0;
  for(i = 0; i < n ;i++){
    ub = ub + A[i];
  }
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    int real_bags = 0;
    for(i = 0; i < n; i++){
      if(A[i] % mid == 0){
        real_bags = real_bags + A[i] / mid;
      }else{
        real_bags = real_bags + A[i] / mid + 1;
      }
    }
    if(real_bags <= k){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
