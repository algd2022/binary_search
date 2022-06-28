#include <stdio.h>
#include <math.h>

int n;
long long k;
int A[100000];

long long CountBagsNeed(int MaxAppleInBag)
{
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (A[i] % MaxAppleInBag == 0)
    {
      ans += A[i] / MaxAppleInBag;
    }
    else
    {
      ans += A[i] / MaxAppleInBag + 1;
    }
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

  int lb = 1, ub = 1e9;

  while (ub - lb > 1)
  {
    int cb = (lb + ub) / 2;
    if (CountBagsNeed(cb) >= k)
    {
      lb = cb;
    }
    else
    {
      ub = cb;
    }
  }

  int ans;

  if (CountBagsNeed(lb) > k)
  {
    ans = ub;
  }
  else
  {
    ans = lb;
  }

  printf("%d\n", ans);

  return 0;
}
