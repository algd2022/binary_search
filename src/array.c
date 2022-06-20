#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

	lb = -1;		//x:��肤��ŏ�0 = �Ԃ�l0
	ub = n;			//x:��肤��ő�n = �Ԃ�l1

	while(ub - lb > 1){
		int mid = (lb + ub) / 2;

		if (A[mid] >= k){
			ub = mid;
		}
		else{
			lb = mid;
		}
	} 
	
	printf("%d\n", ub);		//�ォ��}����
  return 0;
}
