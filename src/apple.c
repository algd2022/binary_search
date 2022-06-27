#include <stdio.h>
#include <stdbool.h>

int n;
int k;
int A[100000];

bool p(int x);
void Num_printing(int i);

int main()
{
  int i, lb = 0, ub = 0;
  printf("Enter n and k:\n");
  scanf("%d%d", &n, &k);
  printf("Check the value:n=%d, k=%d\n", n, k);
  for (i = 0; i < n; ++i)
  {
    Num_printing(i + 1);
    scanf("%d", &A[i]);
    if (ub < A[i])
    {
      ub = A[i];
    }
  }

  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    // printf("x=%d\n", mid);
    if (p(mid))
    {
      // printf("t\n");
      ub = mid;
    }
    else
    {
      // printf("f\n");
      lb = mid;
    }
  }

  printf("Output Number:%d\n", ub);
  return 0;
}

bool p(int x)
{
  unsigned int count = 0;
  for (int i = 0; i < n; i++)
  {
    count += (A[i] + x - 1) / x;
    // printf("%d\n", count);
  }
  if (count <= k)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// 表示をきれいにするためのプログラム
void Num_printing(int i)
{
  if (i % 10 == 1)
  {
    printf("Enter the array value(%d st):\n", i);
  }
  else if (i % 10 == 2)
  {
    printf("Enter the array value(%d nd):\n", i);
  }
  else if (i % 10 == 3)
  {
    printf("Enter the array value(%d rd):\n", i);
  }
  else
  {
    printf("Enter the array value(%d th):\n", i);
  }
}