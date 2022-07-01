#include <stdio.h>

int n;
int k;
int A[100000];

int p(x)
{
  int t = 1;
  int work = 0;
  for (int i = 0; i < n; i++)
  {
    if (A[i] > x){
      return 0;
    }
    if(work + A[i] > x){
      work = A[i];
      t += 1;
    }
    else{
      work += A[i];
    }
  }
  return t <= k;
}

int bin_search(int lb, int ub)
{

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
  return ub;
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
  // 最大値は1e9(10^5時間,10^4の仕事を一人で行う場合)
  ub = 1e9;
  int ans = bin_search(lb, ub);
  printf("%d", ans);
  return 0;
}
