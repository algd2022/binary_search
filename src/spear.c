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

  if (SumSpear(1) < k)
  {
    printf("%d\n", 0);
    return 0;
  }

  int lb = 1, ub = 1e9;

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

  int ans;

  if (SumSpear(ub) < k)
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
