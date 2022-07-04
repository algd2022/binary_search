#include <stdio.h>

int n;
int k;
int A[100000];

int max(int n, int *A) {
  int i, max = A[0];
  for(i = 1; i < n; i++){
    if(A[i] > max)
       max = A[i];
  }
  return max;
}
unsigned int p(int x, int A[]){
  int i, sum=0;
  for(i = 0; i < n; i++){
    sum += A[i] / x;
  }
  return sum < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = max(n, A);
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(mid, A)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
