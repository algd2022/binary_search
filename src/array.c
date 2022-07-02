#include <stdio.h>

int n;
int k;
int A[100000];

void Num_printing(int i);

int main()
{
  int i, lb, ub;
  printf("Enter n and k:\n");
  scanf("%d %d", &n, &k);
  printf("Check the value:n=%d, k=%d\n", n, k);
  for (i = 0; i < n; i++)
  {
    Num_printing(i + 1);
    scanf("%d", &A[i]);
  }

  lb = -1;
  ub = n;

  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    if (A[mid] >= k)
    {
      ub = mid;
    }
    else
    {
      lb = mid;
    }
  }

  printf("Output Number:%d\n", ub);

  return 0;
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