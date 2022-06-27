#include <stdio.h>

int n;
int k;
int A[100000];

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 0;
  for (i = 0; i < n; i++)
  {
    if (ub < A[i])
      ub = A[i];
  }
  ub++;
  while (ub - lb > 1)
  {
    int mid = lb + (ub - lb) / 2;
    long long sum = 0;
    for (i = 0; i < n; ++i)
    {
      sum += A[i] / mid;
    }
    if (sum >= k)
    {
      lb = mid;
    }
    else
    {
      ub = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
