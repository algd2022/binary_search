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
  ub = 1000000001;
  int siguma;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    siguma = 0;
    for(i = 0; i < n; i++){
      siguma = siguma + A[i] / mid;
    }
    if(siguma >= k){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }

  printf("%d\n", lb);
  return 0;
}
