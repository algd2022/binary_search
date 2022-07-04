#include <stdio.h>
#include <stdbool.h>

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

  // ub->仕事を割り振れる最小のx
  // lb->仕事を割り振れない最大のx
  ub = (int)1E9;
  lb = 0;
  while (ub > lb + 1)
  {
    int mid = (ub + lb) / 2;
    int work_num = 0, people_num = 0;
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
      if (A[i] > mid)
      {
        ok = false;
        break;
      }
      else if (work_num + A[i] > mid)
      {
        work_num = A[i];
        people_num++;
      }
      else
      {
        work_num += A[i];
      }
    }
    people_num++;
    ok &= people_num <= k;
    if (ok)
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
