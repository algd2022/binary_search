#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int l = 0;
  int sum = 0;
  while (l < n){
   sum += (A[l] + x - 1) / x;
   l += 1;
  }
  return sum <= k;
}

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
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}