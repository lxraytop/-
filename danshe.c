#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void danshe(int *a, int *b, int m, int n, int *twice, int *result, int chu) {
	if (chu == m) {//按格式输出
		printf("{");
		for (int i = 0; i < m; i++) {
			printf("<%d,%d>", a[i], b[result[i]]);
			if (i != m - 1) {
				printf(",");
			}
		}
		printf("}\n");
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!twice[i]) {//判断重复
			twice[i] = 1;
			result[chu] = i;
			danshe(a, b, m, n, twice, result, chu + 1);
			twice[i] = 0;
		}
	}
}
int sortb(const void *a, const void *b) {  //比较
	return (*(int*)a - *(int*)b);  
}  

int main() {  
	int m, n;  
	scanf("%d %d", &m, &n);  
	int a[m];  
	int b[n];  
	for (int i = 0; i < m; i++) {  
		scanf("%d", &a[i]);  
	}  
	for (int i = 0; i < n; i++) {  
		scanf("%d", &b[i]);  
	}  
	qsort(a, m, sizeof(int), sortb);  //排序
	qsort(b, n, sizeof(int), sortb);  
	int twice[n];  
	memset(twice, 0, sizeof(twice)); 
	int result[m];  
	danshe(a, b, m, n, twice, result, 0);  
	return 0;  
}
