#include <stdio.h>

int n;
int k;
int A[100000];

//関数pの定義
int p(int n, int k, int A[], int x){
	int i=0, num=1, m=0; //num:必要人数(ラスト一人分の1を予め加える)、m:各人のトータルの仕事量を計算
	for(i=0;i<n;i++){ //x<A[i]となる場合は1〜(i-1)までの処理が無駄になるので先にその場合があるか調べる
		if(x<A[i]){
			return 0;
		}
	}
	for(i=0;i<n;i++){
		m=m+A[i];
		if(x<m){
			m=A[i];
			num++;
		}
	}
	return num<=k;
}

int main(){
  int i, lb, ub;
  //入力
  printf("n,kを入力してください\nただし、\n1<=n<=100000\n"
		  "1<=k<=n\n"
		  "となる様入力してください\n");
  scanf("%d%d", &n, &k);
  while(1){ //入力制限を満たす様調節
	  if((n<=100000)&&(n>=1)&&(k<=n)&&(k>=1)) break;
	  printf("1<=n<=100000\n1<=k<=n\nとなる様入力してください\n");
      scanf("%d%d", &n, &k);
  }
  printf("a1〜anを入力してください\nただし、\n"
		  "1<=ai<=10000 (i=1,1,2,...,n)\n"
		  "となる様入力してください\n");
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    while(1){ //入力制限を満たす様調節
    	if((A[i]<=10000)&&(A[i]>=1)){
    		break;
    	}
    	printf("1<=a%d<=10000となる様入力してください\n",i+1);
        scanf("%d", &A[i]);
    }
  }
  //二分探索(関数pを用いた応用形)
  lb = 0;
  ub = 10000;
  while(ub - lb > 1){
      int mid = (lb + ub)/2;
      if(mid==0){
    	  ub=A[0];
    	  break;
      }
      if(p(n,k,A,mid)) ub = mid;
      else lb = mid;
  }
  printf("求める仕事量xは%dです",ub);
  return 0;
}