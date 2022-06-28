#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m)
{
  int work = 1; /*仕事をする人数*/
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (A[i] > m)
    {
      return 0;
    }
    sum += A[i];
    if (sum > m)
    {
      sum = A[i];
      work += 1;
    }
  }
  if (work <= k)
    return 1;
  else
    return 0; /*仕事を割り振れないとき*/
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
  ub = 1e9;
  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
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
