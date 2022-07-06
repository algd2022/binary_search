#include <stdio.h>
#include <math.h>

int n;
long long k;
int A[100000];

int checkAllocWork(int MaxWorkAmount)
{
  int AllocatedPersonCount = 1;
  int workAmount = 0;
  for (int i = 0; i < n; i++)
  {
    if (workAmount + A[i] <= MaxWorkAmount)
    {
      workAmount += A[i];
    }
    else
    {
      if (A[i] > MaxWorkAmount)
      {
        return 0;
      }
      AllocatedPersonCount++;
      workAmount = A[i];
    }
  }
  if (AllocatedPersonCount <= k)
  {
    return 1;
  }
  else
  {
    return 0;
  }
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
    if (checkAllocWork(cb))
    {
      ub = cb;
    }
    else
    {
      lb = cb;
    }
  }

  printf("%d\n", ub);

  return 0;
}
