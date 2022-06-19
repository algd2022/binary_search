#include <stdio.h>

int n;
int k;
int A[100000];

int p(int mid)
{
  int ans = 0;
    for(int i = 0; i< n;i++)
      ans += A[i]/mid;
    return ans < k;
}//

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  lb = 0;//長さ０は絶対作れる、の中の最大値。つまりp(lb)==0
  ub = 1e9+1;//p(ub)==1絶対に作れない。の中の最小値
  while(ub-lb>1)
  {
    int mid = (ub+lb)/2;
    if(p(mid))//もしそれが真、つまり作れなかったら、ubを更新する
      ub = mid;
    else
      lb = mid;
  }
  printf("%d\n",lb);//作れたものの最大値がlb

  return 0;
}
