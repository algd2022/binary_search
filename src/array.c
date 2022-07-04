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

  lb = -1;
  ub = n;

  int mid = (lb + ub) / 2;

  while (ub - lb > 1)
  {
    if (A[mid] >= k)
      ub = mid;
    else
      lb = mid;

    mid = (lb + ub) / 2;
  }

  printf("%d", ub);

  return 0;
}
