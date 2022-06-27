#include <stdio.h>

int n;
int k;
int A[100000];

//長さxの槍をk本以上作れるのなら0、作れないなら1を返す
int p(int x)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += A[i] / x;
  }
  if (sum < k)
  {
    return 1;
  }
  return 0;
}

int main()
{
  int i, lb, ub;

  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while (ub > 1 + lb)
  {
    int mid = (ub + lb) / 2;
    if (p(mid))
    {
      ub = mid;
    }
    else
    {
      lb = mid;
    }
  }

  printf("%d\n", lb);
  return 0;
}
