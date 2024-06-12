#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// 函数用于判断两个字符串是否等价
int isEquivalent(char *str1, char *str2) {
	int count1[128] = {0}; // 记录字符串1中每个字符的出现次数
	int count2[128] = {0}; // 记录字符串2中每个字符的出现次数
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	// 统计字符串1中每个字符的出现次数
	for (int i = 0; i < len1; i++) {
		count1[str1[i]]++;
	}
	
	// 统计字符串2中每个字符的出现次数
	for (int i = 0; i < len2; i++) {
		count2[str2[i]]++;
	}
	
	// 比较两个字符串中每个字符出现的次数是否相等
	for (int i = 0; i < 128; i++) {
		if (count1[i] != count2[i]) {
			return 0; // 如果有不相等的字符出现次数，返回0
		}
	}
	
	return 1; // 如果所有字符的出现次数都相等，返回1
}

int main() {
	int N;
	char str1[MAX_LEN], str2[MAX_LEN];
	
	// 读取输入数据
	while (scanf("%d", &N) != EOF) {
		scanf("%s %s", str1, str2);
		
		// 判断两个字符串是否等价并输出结果
		if (isEquivalent(str1, str2)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}
