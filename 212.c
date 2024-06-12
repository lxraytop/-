#include <stdio.h>

// 定义一个常量表示模糊集合元素的最大个数
#define MAX_SIZE 100

// 模糊集合结构体
typedef struct {
    int n; // 元素个数
    double elements[MAX_SIZE]; // 元素数组
} FuzzySet;

// 定义函数用于计算并集
void unionSet(FuzzySet A, FuzzySet B) {
    for (int i = 0; i < A.n; i++) {
        printf("%.6lf ", A.elements[i]);
    }
    for (int i = 0; i < B.n; i++) {
        printf("%.6lf ", B.elements[i]);
    }
}

// 定义函数用于计算交集
void intersectSet(FuzzySet A, FuzzySet B) {
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < B.n; j++) {
            if (A.elements[i] == B.elements[j]) {
                printf("%.6lf ", A.elements[i]);
                break;
            }
        }
    }
}

// 定义函数用于计算补集
void complementSet(FuzzySet A) {
    for (int i = 0; i < A.n; i++) {
        printf("%.6lf ", 1 - A.elements[i]);
    }
}

int main() {
    FuzzySet A, B;
    int T; // 1表示求交集，2表示求并集，3表示求补集

    // 读取输入
    scanf("%d", &A.n);
    for (int i = 0; i < A.n; i++) {
        scanf("%lf", &A.elements[i]);
    }
    scanf("%d", &B.n);
    for (int i = 0; i < B.n; i++) {
        scanf("%lf", &B.elements[i]);
    }
    scanf("%d", &T);

    // 根据T的值调用相应的函数计算集合运算结果
    switch (T) {
        case 1:
            intersectSet(A, B);
            break;
        case 2:
            unionSet(A, B);
            break;
        case 3:
            complementSet(A);
            break;
        default:
            printf("Invalid input for T\n");
    }
    
    return 0;
}
