#include <stdio.h>

int n;
int k;
int A[100000];

//関数pを定義
int p(int n, int k, int A[], int x){
	int i=0, j;
	long long int m=0;
	if(x==0){
		return 0;
	}
	for(i=0;i<n;i++){
		j=(A[i]+x-1)/x;
		m=m+j;
	}
	return m<=k;
}

int main(){
  int i, lb, ub;
  //入力
  printf("n,kを入力してください\nただし、\n1<=n<=100000\n"
		  "n<=k<=100000\n"
		  "となる様入力してください\n");
  scanf("%d%d", &n, &k);
  while(1){ //入力制限を満たす様調節
	  if((n<=100000)&&(n>=1)&&(k<=100000)&&(k>=n)) break;
	  printf("1<=n<=100000\nn<=k<=100000\nとなる様入力してください\n");
      scanf("%d%d", &n, &k);
  }
  printf("a1〜anを入力してください\nただし、\n"
		  "1<=ai<=1000000000 (i=1,1,2,...,n)\n"
		  "となる様入力してください\n");
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    while(1){ //入力制限を満たす様調節
    	if((A[i]<=1000000000)&&(A[i]>=1)){
    		break;
    	}
    	printf("1<=a%d<=1000000000となる様入力してください\n",i+1);
        scanf("%d", &A[i]);
    }
  }
  //二分探索(関数pを用いた応用形)
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
      int mid = (lb + ub)/2;
      if(mid==0){
    	  ub=A[0];
    	  break;
      }
      if(p(n,k,A,mid)) ub = mid;
      else lb = mid;
  }
  printf("求める最小値xは%dです",ub);
  return 0;
}
