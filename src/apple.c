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

  // ub->全員がリンゴを入れられる最小のx
  // lb->リンゴが入りきらない最大のx
  ub = (int)1E9;
  lb = 0;
  while (ub > lb + 1)
  {
    int mid = (ub + lb) / 2;
    int used_bag = 0;
    for (int i = 0; i < n; i++)
    {
      used_bag += (A[i] - 1) / mid + 1;
    }
    if (used_bag <= k)
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
