#include <stdio.h>

int n;
int k;
int A[100000];

int sum()
{
  int ret = 0;

  for (int i = 0; i < n; i++)
  {
    ret += A[i];
  }

  return ret;
}

int p(int x)
{
  int num = 0;
  int work = 0;

  for (int i = 0; i < n; i++)
  {
    work += A[i];
    if (work > x)
    {
      num++;
      // exception
      if (A[i] > x)
      {
        return 0;
      }
      else
      {
        work = A[i];
      }
    }
  }

  return (num < k);
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
  ub = sum();

  int mid = (lb + ub) / 2;

  while (ub - lb > 1)
  {
    if (p(mid))
      ub = mid;
    else
      lb = mid;

    mid = (lb + ub) / 2;
  }

  printf("%d", ub);

  return 0;
}
