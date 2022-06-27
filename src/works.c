#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int sum = 0;
  int num = 1;
  for(int i = 0; i < n; i++){
    if(sum + A[i] <= m){
      sum = sum + A[i];
    }
    else if(A[i] <= m){
      sum = A[i];
      num = num +1;
    }
    else{
      return 0;
    }
  }
  return num <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
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
