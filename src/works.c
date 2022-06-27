#include <stdio.h>

int n;
int k;
int A[10000];

// 1人当たりの仕事量の最大値がxの時、k人に仕事を割り当て可能なら1、不可能なら0を返す
int p(int x)
{
  int i = 0;
  // j番目の人に仕事量work(x以下)を割り当てる。
  for (int j = 0; j < k; j++)
  {
    int work = 0;
    while (work < x)
    {
      if (A[i] > x)
      {
        return 0;
      }
      if ((x - work) >= A[i])
      {
        work += A[i++];
      }
      else
      {
        break;
      }
      // A[0]~A[n-1]まで配分済み
      if (i == n)
      {
        return 1;
      }
    }
  }
  // k人にA[0]~A[i](i<n-1)まで配分したがA[i+1]~A[n-1]を配分できていない
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
