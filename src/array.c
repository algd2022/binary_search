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

  int lb = -1, ub = n;
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
