#include <stdio.h>

int n;
int k;
int A[100000];

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  // ub->槍を作れない最小のx
  // lb->槍を作れる最大のx
  ub = (int)1E9 + 1;
  lb = 0;
  while (ub > lb + 1)
  {
    int mid = (ub + lb) / 2;
    int spear_num = 0;
    for (int i = 0; i < n; i++)
    {
      spear_num += A[i] / mid;
    }
    if (spear_num < k)
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
