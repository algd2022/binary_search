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
  lb = (int)(1e9) + 1;
  ub = 0;
  for (i = 0; i < n; i++)
  {
    if (ub < A[i])
      ub = A[i];
    if (lb > A[i])
      lb = A[i];
  }
  lb--;
  while (ub - lb > 1)
  {
    int mid = (ub + lb) / 2; // it will not overflow if you use gcc which use 32bit as int!
    long long cnt = 0;       // avoid overflow
    for (i = 0; i < n; ++i)
    {
      cnt += (A[i] + mid - 1) / mid; // it will not overflow if you use gcc!
    }
    if (cnt <= (long long)(k))
    {
      ub = mid;
    }
    else
    {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}