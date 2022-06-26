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

  return max_p;
}

int sup_about()
{
  return ceiling((double)max() / ((int)k / n));
}

int p(int x)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += (int)(A[i] / x);
  }

  return (k <= sum);
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
  ub = sup_about();

  int mid = (lb + ub) / 2;

  while (ub - lb > 1)
  {
    if (p(mid))
      lb = mid;
    else
      ub = mid;
    mid = (ub + lb) / 2;
  }

  printf("%d", lb);

  return 0;
}
