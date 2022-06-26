#include <stdio.h>

int n;
int k;
int A[100000];

int ceiling(double x)
{
  if (x == (int)x)
  {
    return x;
  }
  else
  {
    return ((int)x + 1);
  }
}

int max()
{
  int max_p = 0;
  for (int i = 0; i < n; i++)
  {
    if (A[i] > max_p)
    {
      max_p = A[i];
    }
  }

  return n * max_p;
}

int p(int x)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += ceiling((double)A[i] / x);
  }

  return (sum <= k);
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
  ub = max();

  int mid = (ub + lb) / 2;

  while (ub - lb > 1)
  {
    if (p(mid))
      ub = mid;
    else
      lb = mid;

    mid = (ub + lb) / 2;
  }

  printf("%d", ub);

  return 0;
}
