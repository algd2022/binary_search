#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int i, num, sum; /*仕事する人の番号num, 一人の仕事量の合計sum */
  sum = 0;
  num = 1;
  for(i = 0; i < n; i++){
    if(A[i] <= x) sum += A[i];
    else return 0; /*xはA[i]の最大値以上であるため、x < A[i] のとき return 0 */
    if(sum > x){ /*仕事量の合計がxを超えたとき次の人が仕事を始める*/
      num ++;
      sum = A[i];
    }
  }
  if(num <= k) return 1;
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000; /*ΣA[i] <= n * 10^4 <= 10^5 * 10^ 4 = 10^9*/
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid ;
    else lb = mid ;
  }
  printf("%d\n", ub);

  return 0;
}
