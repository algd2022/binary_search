#include <stdio.h>
#include <math.h>


int n;
int k;
int A[100000];

int max1(int len, int *nums) {
    int i, max = nums[0];
    for (i = 0; i < len; i++) {
        if (nums[i] > max)
            max = nums[i];
    }
    return max;
}

int p (int A[], int x, int n, int k){
  int sum = 0;
  for (int i = 0; i < n; i++){
    //printf("%f, base:%f, x:%d, A[i]: %d\n", floor((double)A[i] / (double)x), (double)A[i] / (double)x, x, A[i]);
    sum += floor((double)A[i] / (double)x);
  }
  int z;
  //printf("sum: %d\n", sum);
  if (sum < k) z = 1;
  else z = 0;
  return z;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = max1(k, A);
  //printf("ub= %d\n", ub);

  while(ub - lb > 1) {
    int mid = (lb + ub) / 2; 
    //printf("mid: %d,  ub: %d, lb: %d\n", mid, ub,lb);
    if(p(A, mid, n, k)){
      ub = mid; 
    } else {
      lb = mid;
    } 
  }

  printf("%d\n", lb);
  /* lbが条件を満たす最大値になっている。*/

  return 0;
}
