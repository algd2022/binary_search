#include <stdio.h>

int n;
int k;
int A[100000];



int p(int m){                  //mを変数にとる関数p()を設定
    int length = 0;            //仕事を前順から一人分だけ積んでいくときの、その人分の割り当て仕事の総量
    int sum = 1;               //要する総人数sumを定義　初期値は1
    for(int q = 0;q < n;q++){  //変数qについて以下の操作を繰り返し
      if(length + A[q] <= m){  //その人分の仕事量に、さらに次の時間分を割り当ててもmを越えなければ
        length = length + A[q];//仕事追加を実行
      }
      else if(A[q] > m){       //ある1時間当たりの仕事がmを超えるとき、mはxの候補になりえないので
        return 0;              //0を返して繰り返し終了
      }
      else{                    //その人分の仕事量に、さらに次の時間分を割り当てるとmを超える時
        length = A[q];         //その仕事を次の人に割り当てる
        sum = sum + 1;         //次の人分の人数をカウント
      }

    }  
    return sum <= k;           //単調関数の設定
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    lb = 0;                    //領域下限の初期値を0に設定(1と設定するとn=k=1 a_1=1のとき1を返せない)
    ub = 1000000000;           //領域上限の初期値を10^9(n=k=1 a_1=10^9のときの割り当て仕事量で採用する値)に設定
    while(ub - lb > 1){        //ub > lb+1の間以下を繰り返し
      int mid = (lb + ub) / 2; //領域中央値midの定義
      if(p(mid)){              //p(mid)が1であれば
        ub = mid;              //領域上限ubをmidの値に指定
      }
      else {                   //p(mid)が0であれば
        lb = mid;              //領域下限lbをmidの値に指定
    }
    }
  }

  printf("%d\n",ub);           //繰り返し終了後のubの値(求める値x)を出力
  return 0;
}

