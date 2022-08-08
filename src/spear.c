#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int x)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += A[i] / x;
  }

  return sum < k;
}

int main()
{
  int i;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  int lb = 0;
  int ub =  1000000000;

  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;

    if (p(mid))
      ub = mid;
    else
      lb = mid;
  }

  printf("%d", lb);

  return 0;
}
