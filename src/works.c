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
  for (i = 0; i < n; ++i)
  {
    if (lb < A[i])
      lb = A[i];
    ub += A[i];
  }
  lb--;
  while (ub - lb > 1)
  {
    int mid = lb + (ub - lb) / 2;
    int pos = 0, cnt = 0, sum = 0;
    while (pos < n)
    {
      if (sum + A[pos] > mid)
      {
        sum = 0;
        cnt++;
        continue;
      }
      sum += A[pos++];
    }
    cnt++;
    if (cnt > k)
    {
      lb = mid;
    }
    else
    {
      ub = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
