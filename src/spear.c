#include <stdio.h>

  int n;
  int k;
  int A[100000];




  int main() {
      int i, lb, ub;
      scanf("%d%d", &n, &k);
      for (i = 0; i < n; i++) {
          scanf("%d", &A[i]);
      }

      int x = 1;
      while (1) {
          int s = 0;
          int m = 1;
          int o = 0;
          while (1) {

              lb = -1;
              ub = n;

              while (ub - lb > 1) {
                  int mid = (lb + ub) / 2;
                  if (A[mid] >= x * m) {
                      ub = mid;
                  }
                  else {
                      lb = mid;
                  }
              }
              s = s + (m-1) * (ub - o);
              o = ub;
              if (ub == n) {
                  break;
              }
              else {
                  m = m + 1;
              }

          }

          printf("s=%d\n", s);

          if (s < k) {
              x = x-1;
              break;
          }
          else {
              x = x + 1;
          }
      }



      printf("%d\n", x);

      return 0;
  }
