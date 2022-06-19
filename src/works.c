#include <stdio.h>

int n;
int k;
int A[100000];

int p(int mid)
{
  int temp = 0;
  int i = 0;
  int count = 0;
  while(i < n)
  {
    if(A[i] > mid)//絶対そのような配分はできない
    {
      return 0;
    }
    temp += A[i];
    if(temp > mid)//もしそうだったら、１個もどす
    {
      temp =0;
      count++;
      i--;
    }
    i++;
  }
  if(temp <= mid)//最後の取りこぼしたものでもみる
  {
    count++;
  }
  if(count > k)
    return 0;
  else 
  {
    return 1;
  }
}


int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  lb = 0; //絶対に無理
  ub = 1e9; //全ての仕事を一人に任せるから絶対にできる
  while(ub - lb >1)
  {
    int mid = (ub+lb)/2;
    if(p(mid))
      ub = mid;
    else
      lb = mid;
  }

  printf("%d\n",ub);


  return 0;
}
