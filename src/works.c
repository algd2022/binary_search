#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x)
{
  int i = 0;
  for (int j = 0; j < k; j++)
  {
    int x2 = x - A[i];
    while (x2 >= 0)
    {
      i++;
      if (i == n)
        return 1;
      x2 -= A[i];
    }
  }
  return 0;
}

unsigned int binary_search(int (*A)(int), int x, int n)
{
  int lb = -1;
  int ub = n;
  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    if (A(mid) >= x)
      ub = mid;
    else
      lb = mid;
  }
  return ub;
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
