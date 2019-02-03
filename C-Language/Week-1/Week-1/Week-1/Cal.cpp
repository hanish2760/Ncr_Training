#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Sum.cpp";
#include "Sub.cpp";
#include "Mul.cpp";
#include "Div.cpp";


void cal() {

	int a = -1;
	int b = -1;
	printf("Enter numbers a and b\n");

	scanf("%d,%d", &a, &b);

	printf("Select one 1)add2)sub3)mul4)div\n");
	int choice = -1;
	scanf("%d", &choice);
	int res = -1;
	switch (choice) {
	case 1:
		res = sums(a, b);
		break;
	case 2:
		res = subs(a, b);
		break;
	case 3:
		res = muls(a, b);
		break;
	case 4:
		res = divs(a, b);
		break;
	default:
		printf("select option correctly\n");
		break;

	}
	printf(" \n res = %d", res);


	return;
}