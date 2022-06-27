#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += A[i] / x;
  }
  return sum < k; /*sumは切り捨てられた値であり、求める最小値より小さいxで 　　　　　　　　
                    sum = k となることがあるため sum = k は偽にしておく*/
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000001; /*lb = 10^9となることがあるため、ub = 10^9 +1 とする*/
  while (ub - lb > 1) {
     int mid = (ub + lb) / 2;
     if (p(mid))  ub = mid;
     else lb = mid;
   }
   printf("%d\n", lb); /*sum = k を偽にしたことにより、
   　　　　　　　　　　　求めたい最小値はlbに代入されているためlbを出力する*/

  return 0;
}
