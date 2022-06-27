#include <stdio.h>

int n;
int k;
int A[100000];

//バッグに入るりんごの数がx個の時、バッグがk個で足りるなら1、足りないなら0を返す
int p(int x)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += (A[i] + x - 1) / x;
  }

  if (sum <= k)
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
  printf("%d\n", ub);
  return 0;
}
