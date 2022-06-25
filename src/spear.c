#include <stdio.h>

int n;
int k;
int A[100000];

// (長さ x の槍の製作可能本数) < k　の時、 p = 1
int p(int x){
  int sum = 0;
  for (int i = 0; i < n; i++){
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
  ub = 1000000001;

  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    if (p(mid))  ub = mid;
    else lb = mid;
  }

  printf("%d\n", lb);  // lb = ub - 1 

  return 0;
}
