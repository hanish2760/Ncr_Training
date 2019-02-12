#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


void count(FILE* fp) {
	int a = 0, d = 0, s = 0, sc = 0;
	do {


		if (feof(fp)) {
			sc--;
			break;
		}

		char c = fgetc(fp);
		
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
			a++;
		else if ('0' <= c && c <= '9') d++;
		else if (c == ' ')s++;
		else sc++;
		if (c == '\n' || c == '\t')sc--;


	} while (1);
	printf("%d- alphabets , %d - digits ,%d - spaces ,%d - special characters",a,d,s,sc);
	getchar();

	fclose(fp);
	return;
}