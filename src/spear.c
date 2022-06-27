#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub, mid, sum, max = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i] > A[max])max = i;
  }

  lb = 0;
  ub = A[max];

  while (ub - lb > 1){
    sum = 0;
    mid = (lb + ub) / 2;
    for(i = 0; i < n; i++){
      sum += A[i] / mid;
    }
    if(sum < k) ub = mid;
    else lb = mid;
  }

  printf("%d", lb);
  
  return 0;
}
