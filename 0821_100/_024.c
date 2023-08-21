#include <stdio.h>

void my_strcpy(char* stra, char* strb) {
	while (*stra != '\0') {
		*strb = *stra;
		stra++; strb++;
	}
	stra = '\0';
}

int main() {
	char stra[30], strb[30];
	scanf("%[^\n]", stra);

	my_strcpy(stra, strb);

	printf("%s\n", stra);
	printf("%s\n", strb);
	return 0;
}