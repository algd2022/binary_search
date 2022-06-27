#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i, lb, ub;
  //入力
  printf("n,kを入力してください\nただし、\n1<=n<=100000\n"
		  "1<=k<=1000000000\n"
		  "となる様入力してください\n");
  scanf("%d%d", &n, &k);
  while(1){ //入力制限を満たす様調節
	  if((n<=100000)&&(n>=1)&&(k<=1000000000)&&(k>=1)) break;
	  printf("1<=n<=100000\n1<=k<=1000000000\nとなる様入力してください\n");
      scanf("%d%d", &n, &k);
  }
  printf("a0〜an-1を入力してください\nただし、\n"
		  "1<=ai<=1000000000 (i=0,1,2,...,n-1)\n"
		  "ai<=ai+1(i=0,1,2,...,n-2)\n"
		  "となる様入力してください\n");
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    while(1){ //入力制限を満たす様調節
    	if((A[i]<=1000000000)&&(A[i]>=1)){
    		break;
    	}
    	printf("1<=a%d<=1000000000となる様入力してください\n",i);
        scanf("%d", &A[i]);
    }
    while(1){
    	if(i==0){
    		break;
    	}
    	if(A[i-1]<=A[i]){
    		break;
    	}
        printf("1<=a%d<=1000000000\n"
          		"a%d<=a%d+1\n"
           	    "となる様入力してください\n",i,i,i);
   		scanf("%d", &A[i]);
   		if((k>1000000000)||(k<1)){
           	printf("1<=a%d<=1000000000となる様入力してください\n",i);
           	scanf("%d", &A[i]);
   		}
    }
  }
  //二分探索
  lb = -1;
  ub = n;
  while(ub - lb > 1){
      int mid = (lb + ub)/2;
      if(A[mid]>=k) ub = mid;
      else lb = mid;
  }
  printf("求める最小の整数xは%dです",ub);
  return 0;
}