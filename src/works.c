#include <stdio.h>

int n;
int k;
int A[100000];

int main()
{
  int i;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  int lb = 0;
  int ub = 100000000;

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

unsigned int p(int x)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += A[i] / x;
  }

  return sum < k;
}
#include <stdio.h>

int n;
int k;
int A[100000];

int main()
{
  int i;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  int lb = 0;
  int ub = 100000000;

  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;

    if (p(mid))
      ub = mid;
    else
      lb = mid;
  }

  printf("%d", ub);

  return 0;
}

unsigned int p(int x)
{
  int sum = 0;
  int a = 1;
  for (int i = 0; i < n; i++)
  {
    if (A[i] > x)
      return 0;

    sum += A[i];
    if (sum > x)
    {
      sum = A[i];
      a++;
    }
  }

  return a <= k;
}
