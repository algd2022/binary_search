#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int x){
  unsigned int sum = 0;
  for (int i=0; i<n; i++){
    sum += (A[i] + x - 1) / x;
  }
  return sum <= k;
}
int main(){
  int i, lb, ub;
  printf("a\n");
  scanf("%d%d", &n, &k);
  printf("b\n");
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);}

  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){ub = mid;}
    else {lb = mid;}
  }
  printf("%d\n", ub);
  return 0;
}

