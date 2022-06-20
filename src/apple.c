#include <stdio.h>

int n;
int k;
int A[100000];

int p(x)
{
  int t = 0;
  for (int i = 0; i < n; i++)
  {
    t += (A[i] + x - 1) / x;
  }
  return t <= k;
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
  lb = 0;
  ub = 1e9 + 1;
  int ans = bin_search(lb, ub);
  printf("%d", ans);
  return 0;
}
