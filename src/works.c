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

int sum(int len, int *nums) {
    int i, sumA = 0;
    for (i = 0; i < len; i++) {
      //printf("%d\n", nums[i]);
      sumA += nums[i];
    }
    return sumA;
}

int p (int A[], int hp, int n, int num){
  int hp_base = hp;
  //printf("before, hp: %d, num: %d\n", hp, num);

  for (int i = 0; i < n; i++){
    if(hp - A[i] < 0){
      //printf("hit, num-1,  i=%d\n", i);
      hp = hp_base - A[i];//これは0を下回ることはない(lb >= max(*A) より)
      num -= 1;
    } else hp -= A[i];
    //printf("hp: %d, i=%d\n", hp, i);
  }
  //printf("after, hp: %d, num: %d\n\n", hp, num);

  int ans;
  //num>0なら良い
  if(num > 0) ans = 1;
  else ans = 0;

  return ans;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = max1(n, A)-1;
  ub = sum(n, A);
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

  printf("%d\n", ub);
  /* lbが条件を満たす最大値になっている。*/

  return 0;
}
