#include <stdio.h>

int n;
int k;
int A[100000];

int P(int x)
{
  int s = 1;
  int tmp = 0;
  for (int i = 0; i < n; i++)
  {
    tmp += A[i];
    if (tmp > x)
    {
      // A[i]>=xは保証されている
      tmp = A[i];
      s++;
    }
  }
  return s <= k;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 1;
  ub = 0;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
    lb = max(lb, A[i]);
    ub += A[i];
  }
  lb -= 1;
  // P(x)=1となる最小のxを二部探索で求める
  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    if (P(mid))
    {
      ub = mid;
    }
    else
    {
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
