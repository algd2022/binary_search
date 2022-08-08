#include <stdio.h>
// #include <math.h>

int n;
int k;
int A[100000];

int p(int x)
{
  if (x == 0)
    return 0;

  int k2 = k;
  for (int i = 0; i < n; i++)
  {
    double f = A[i] / (double)x;
    // k2 -= ceil(f);
    k2 -= f == (int)f ? (int)f : (int)(f + 1);
  }
  return k2 >= 0;
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
  int i, lb, ub, max = 0;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
    if (A[i] > max)
      max = A[i];
  }

  printf("%d\n", binary_search(p, 1, max));

  return 0;
}
