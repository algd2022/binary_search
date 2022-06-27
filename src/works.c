#include <stdio.h>

int n;
int k;
int A[100000];

/* 指定した下限の仕事量xに対し、その仕事量xを超えるまで
i=0の仕事量から順に足し合わせてゆく。もしある仕事量単体で
xを超えるならそのxは下限なりえないゆえ0を強制的に返す。
そうではないうえで足していった後にもし超えるなら再びカウントを
0に戻して同じように足していく。0に戻した瞬間がl回起こったらxを
超えないぎりぎりの分け方がl+1個ある、ということになる。このlが
もしkを超えていたらxの値が小さすぎて細かく分けないと1人当たり仕事量が
xを簡単に超えてしまうことになるのだから関数は0を返す。k以上ならば
xの値が十分大きく、細かく分けなくても1人当たり仕事量がxを超えない
ことになるから関数は1を返す。このようにすると関数の0と1の境目であるxは
1人当たり仕事量がxをぎりぎり超えない仕事分配法で、しかも境界右の1は分け方は
k以下であることになる。もしここでのlが真にkより小さくても適当に
k個の分担になるようにさらに分割すればよいので、やはいこれが求めるxである。*/
int p(int x){
  int index = 1, quantity = 0, i;
  for(i = 0; i < n; i++){
    if(x < A[i]){
      return 0;
    }
    if(x < quantity + A[i]){
      quantity = 0;
      index = index + 1;
    }
    quantity = quantity + A[i];
  }
  return index <= k;
}

int main(){
  int i, lb, ub;

  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 10000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid) == 1){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
