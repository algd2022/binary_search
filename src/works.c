#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int j = 0,count=0;
    while (1) {
        count++;
        if (A[j] > x)
            return 0;
        int stack = 0;
        while (stack + A[j] <= x) {
            stack += A[j];
            j++;
            if (j >= n)
                return count <= k;
        }
    }
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = n * 10000;
  while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      if (p(mid))
          ub = mid;
      else
          lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
