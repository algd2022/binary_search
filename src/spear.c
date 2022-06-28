#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m)
{
  int spear = 0;
  for (int i = 0; i < n; i++)
  {
    spear += A[i] / m;
  }
  if (spear < k)
    return 1;
  else
    return 0;
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
  ub = 1e9;
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
