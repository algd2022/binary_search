#include <stdio.h>
#include <math.h>

int n;
long long k;
int A[100000];

long long SumSpear(int MaxAppleInBag)
{
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    ans += A[i] / MaxAppleInBag;
  }

  return ans;
}

int main()
{
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  int lb = 0, ub = 1e9;

  while (ub - lb > 1)
  {
    int cb = (lb + ub) / 2;
    if (SumSpear(cb) >= k)
    {
      lb = cb;
    }
    else
    {
      ub = cb;
    }
  }

  printf("%d\n", lb);

  return 0;
}
