#include <stdio.h>

int n;
int k;
int A[100000];

int p(x)
{
  x = 0 - x;
  int t = 0;
  for (int i = 0; i < n; i++)
  {
    t += A[i] / x;
  }
  return t >= k;
}

int bin_search(int lb, int ub)
{

  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    if (p(mid))
    {
      ub = mid;
    }
    else
    {
      lb = mid;
    }
  }
  return ub;
}

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  lb = 0 - 1e9;
  ub = 0;
  int ans = bin_search(lb, ub);
  printf("%d", 0 - ans);
  return 0;
}
