#include <stdio.h>
#include <stdbool.h>

int n;
int k;
int A[100000];

bool check(int x) {
  int need = 0;
  for (int i = 0; i < n; i++) {
    need += (A[i] - 1) / x + 1;
  }
  return need <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (check(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
