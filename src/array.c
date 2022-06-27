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
    printf("lb:%d\tub:%d\n", lb, ub);
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

  printf("lb:%d\tub:%d\n", lb, ub);

  int ans;
  if (lb > k)
  {
    ans = lb;
  }
  else
  {
    ans = ub;
  }

  printf("%d\n", ans);

  return 0;
}
