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
  lb = -1;
  ub = 1;
  for(i = 0; i < n; i++){
    if(ub <= A[i]){
      ub = A[i] + 1;
    }
  }
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(mid == 0){
      lb = mid;
      break;
    }
    int spear_count = 0;
    for(i = 0; i < n; i++){
      spear_count = spear_count + A[i] / mid;
    }
    if(spear_count >= k){
      lb = mid;
    }else{
      ub = mid;
    }
  }
  printf("%d\n", lb);

  return 0;
}
