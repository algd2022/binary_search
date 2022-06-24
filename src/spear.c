#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x)
{
  int k2 = 0;
  for (int i = 0; i < n; i++)
  {
    k2 += (A[i] / x);
  }
  return k2 >= k;
}

unsigned int binary_search(int (*A)(int), int x, int n)
{
  int lb = -1;
  int ub = n;
  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    if (A(mid) >= x)
      lb = mid;
    else
      ub = mid;
  }

  for (int i = ub - 1;; i++)
  {
    if (A(i))
      return i;
  }
}

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  printf("%d\n", binary_search(p, 1, 1000000000));

  return 0;
}
