#include <stdio.h>

int n;
int k;
int A[100000];

//sizeでかばんk個が足りるか確認する関数
int bag(int size)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += (A[i] + size - 1) / size;
  }
  if (sum <= k)
  {
    return 1;
  }
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  // 関数bagをつかって二分探索
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(bag(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

  return 0;
}
