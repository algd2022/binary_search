#include <stdio.h>

int n;
int k;
int A[100000];

int canNotMake(x){
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += A[i] / x;
  }
  if(ans >= k){
    return 0;
  }else{
    return 1;
  }
}

int main(){
  int i, lb, ub;
  lb = 0;
  ub = 1000000001;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(canNotMake(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
