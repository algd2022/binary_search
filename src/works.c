#include <stdio.h>

int n;
int k;
int A[100000];

int max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}

int p(int m)
{
  int tmp = 0;
  int cnt = 0;
  int rslt = 0;
  for (int i = 0; i < n; i++)
  {
    tmp += A[i];
    if (tmp + A[i + 1] > m)
    {
      // 次で規定値を超えてしまう場合は、ここに仕切りを入れる. rsltは最終的な最大値.
      rslt = max(rslt, tmp);
      tmp = 0;
      cnt++;
    }
  }
  if (cnt > k - 1 || rslt > m)
    return 0;
  else
    return 1;
}

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  ub = 1e9;
  lb = 0;

  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    int judge = p(mid);
    if (judge)
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
