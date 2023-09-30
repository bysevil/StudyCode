#include <stdio.h>

void my_strcpy(char* stra, char* strb) {
	while (*strb++ = *stra++) {
		if (*strb == '\0') return;
	}
	
}

int main() {
	char stra[30], strb[30];
	scanf("%[^\n]", stra);

	my_strcpy(stra, strb);

	printf("%s\n", stra);
	printf("%s\n", strb);
	return 0;
}