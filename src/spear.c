#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m)
{
  int rslt = 0;
  for (int i = 0; i < n; i++)
  {
    rslt += A[i] / m;
  }
  return (long long int)rslt < k;
}

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  ub = 1e9 + 1;
  lb = 0;

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
  printf("%d\n", lb);
  return 0;
}
