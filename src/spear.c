#include <stdio.h>
#include <stdbool.h>

int n;
int k;
int A[100000];

bool check(int x) {
  int can = 0;
  for (int i = 0; i < n; i++) {
    can += A[i] / x;
  }
  return can >= k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 1;
  ub = 1000000001;
  if (!check(lb)) {
    printf("%d\n", 0);
    return 0;
  }

  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (check(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }

  printf("%d\n", lb);

  return 0;
}
