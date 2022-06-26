#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){                          //mを変数にとる関数p()を設定
  int sum = 0;                         //要するバッグの数sumを定義
  for(int s = 0; s < n; s++){          //変数sについて以下の操作を繰り返し
    sum = sum + ((A[s] + m - 1) / m);  //1人当たりに要するバッグ数を足す
  } 
  return sum <= k;                     //単調関数の設定
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    lb = 0;                            //領域下限の初期値を0に設定(1と設定するとn=k=1 a_1=1のとき1を返せない)
    ub = 1000000000;                   //領域上限の初期値を10^9(n=k=1 a_1=10^9のときのバッグ容量)に設定
    while(ub - lb > 1){                //ub > lb+1の間以下を繰り返し
      int mid = (lb + ub) / 2;         //領域中央値midの定義
      if(p(mid)){                      //p(mid)が1であれば
        ub = mid;                      //領域上限ubをmidの値に指定
      }
      else {                           //p(mid)が0であれば
        lb = mid;                      //領域上限lbをmidの値に指定
    }
    }
  }

  printf("%d\n",ub);                   //繰り返し終了後のubの値(求める値x)を出力
  return 0;
}

