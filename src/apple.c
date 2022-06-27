#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += (A[i] + x - 1) / x;
    }
    if (sum <= k)
    {
        return 1;
    }
    else return 0;

}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000000;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (p(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }
  printf("%d/n", ub);
  return 0;
}
