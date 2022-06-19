#include <stdio.h>

int n;
int k;
int A[100000];

int p(int mid)
{
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans += (A[i]+mid-1)/mid;

  return ans <= k;
}



int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  

  lb = 0;//０個だったら絶対に入らない、一人一人少なくて１個りんご収穫するから
  ub = 1e9;//これは一人がどれぐらいりんごを取っても入れる
  while(ub -lb >1)
  {
    int mid = (lb + ub) /2;
    if(p(mid))
      ub = mid;
    else 
      lb = mid;
  }


  printf("%d\n", ub);
  return 0;
}
