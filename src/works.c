#include <stdio.h>
#include <stdbool.h>

int n;
int k;
int A[100000];

bool check(int x) {
  int need = 0;
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (now + A[i] <= x) {
      now += A[i];
    } else {
      need += 1;
      now = A[i];
      if (now > x) {
        return false;
      }
    }
  }
  return need + 1 <= k;
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
    int mid = (ub + lb) / 2;
    if (check(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
