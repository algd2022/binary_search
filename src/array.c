#include <stdio.h>

int main()
{
  int n;
  int k;

  scanf("%d%d", &n, &k);
  int A[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  if (A[n - 1] < k)
  {
    printf("%d\n", n);
    return 0;
  }

  int lb = 0, ub = n - 1;
  while (ub - lb > 1)
  {
    int cb = (ub + lb) / 2;
    if (A[cb] >= k)
    {
      ub = cb;
    }
    else
    {
      lb = cb;
    }
  }

  printf("%d\n", ub);
  return 0;
}
