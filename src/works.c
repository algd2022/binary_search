#include <stdio.h>

int n;
int k;
int A[100000];//quantity of job/hour
int job[100000]={0};//job[i]=1,if maximum job is i


int main(){
  int i,j,x,sum=0,work, lb, ub,mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    sum+=A[i];
  }

  for(x=(sum+k-1)/k;x<=sum;x++){//round up sum/k
    j=0;
    for(i=0;i<k;i++){
      work=0;
      while(work+A[j]<=x&&j<n){//
        work+=A[j];
        j+=1;
      }
    }
    if(j==n){
      job[x]=1;
    }
  }

  lb=sum/k;
  ub=sum-1;
  while((ub-lb)>1){
    mid=(lb+ub)/2;
    if(job[mid]==1){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  printf("%d\n",ub);

  return 0;
}
