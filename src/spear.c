#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i,max=0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  for(i = 0; i < n; i++){
    if(A[i] > max) max = A[i];
  }
  int lb = 0;
  int ub = max;
  while (ub - lb > 1){
  int mid = (lb + ub ) / 2;
  int s = 0;
  for(i = 0; i < n; i++){
    s += A[i] / mid;
  }
  if (s < k) ub = mid ;
   else lb = mid ;
}
    printf("%d", lb);
  return 0;
}
