#include <stdio.h>

int n;
int k;
int A[100000];

// �S���̎d���ʂ����ꂼ��m�ȉ��ƂȂ�悤�Ɏd����z�������Ƃ�,
// �K�v�Ȑl������k�ȉ��Ȃ��1��,k���傫���Ȃ��0��Ԃ��悤�Ȋ֐�p(m)���`����.
// p(m)�͒P���񌸏��֐�

int p(int m) {
    int i;
    int workers = 1;
    int works = 0;

    for (i = 1; i < n + 1; i++) {
        if (works + A[i] <= m) { works += A[i]; } // �d����A[i]��ǉ����Ă�,���̐l�̎d���ʂ�m�𒴂��Ȃ��Ȃ��,A[i]��ǉ�����.
        else if (A[i] > m) { return 0; }      // ������L�q���Ȃ���,A[i] > m�ƂȂ�悤�Ȏd�����������ꍇ,workers���i���ɑ����Ă��܂�.
        else if (works + A[i] > m) {  // �d����A[i]��ǉ������Ƃ�,���̐l�̎d���ʂ�m�𒴂���Ȃ��,���̐l�ɂ͊��蓖�Ă�,
            workers++;                // ���̐l���Ă�(�l���𑝂₵),                                   
            works = A[i];             // ���̐l�Ɏd����A[i]��^����.
        }
    }
    if (workers <= k) return 1;
    else return 0;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 1; i < n + 1; i++) {
        scanf("%d", &A[i]);
    }
    // �œK���̂���,lb�͍ő�l,ub�͍ŏ��l��I��.
    lb = 0;           // m=0�̂Ƃ��K��p=0�ƂȂ�.
                      // ���,m=1��n=k�̏ꍇ��p=0�ƂȂ�Ȃ�.
                      // �����,�ő�l�Ƃ���lb=0��I��.     

    ub = 1000000000;    // m=10^9�̂Ƃ�,�K��p=1�ƂȂ�.
                        // ���,m=10^9-1�̂Ƃ�,A[i]=10^4,n=10^5,k=1�̂悤�ȏꍇ��p=1�ƂȂ�Ȃ�.
                        // �����,�ŏ��l�Ƃ���ub=10^9��I��.

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) == 1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;


}