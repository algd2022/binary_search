#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  int siguma;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    for(i = 1; i <=n; i++){
      siguma = siguma + A[i] / mid;
    }
    if(siguma >= k){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n", ub);
  return 0;
}
