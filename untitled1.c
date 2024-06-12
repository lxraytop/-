#include <stdio.h>  
int main() {  
	int n, T;  
	double a[100], b[100], num[100];  
	scanf("%d", &n);  
	for (int i = 0; i < n; i++) {  
		scanf("%lf", &a[i]);  
	}  
	for (int i = 0; i < n; i++) {  
		scanf("%lf", &b[i]);  
	}   
	scanf("%d", &T);  
	switch (T) {  
		case 1:
		for (int i = 0; i < n; i++) {  
			num[i] = a[i] < b[i] ? a[i] : b[i]; 
		}  
		break;  
		case 2: 
		for (int i = 0; i < n; i++) {  
			num[i] = a[i] > b[i] ? a[i] : b[i]; 
		} 
		break;  
		case 3:
		for (int i = 0; i < n; i++) {  
			num[i] = 1.0 - a[i]; 
		}
		break;  
	}  
	for (int i = 0; i < n; i++) {  
		printf("%.6lf ", num[i]);  
	}  
	return 0;  
}  


