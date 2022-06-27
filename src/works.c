#include <stdio.h>

int n;
int k;
int A[100000];
//一人当たりの最大の仕事量xの時k人以下でn時間の仕事をこなせるかを返す関数。xについて単調非減少。
int enough_work(int x){
  int i, worker = 1, tmp = 0; //workerは仕事を終えるまでに必要な人数。tmpは各人が行っている仕事量を一時的に格納する変数
  for(i = 0; i < n; i++){
    if(A[i] > x) return 0; //xを超える仕事量の1時間があるとき、誰もその仕事を行うことはできず失敗
    else if(tmp + A[i] > x){ //tmpがxを超える場合は次の人に仕事を託す
      worker++;
      tmp = A[i];
    }
    else{
      tmp += A[i];
    }
  }
  return worker <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //enough_worker(lb)=0となる最大の整数。制約から考えられるxの最小値は1
  ub = 1e9; //enough_worker(ub)=1となる最小の整数。制約から考えられるxの最大値は(10^4)*(10^5)=10^9
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(enough_work(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n",ub);

  return 0;
}
