#include<stdio.h>
#include<stdlib.h>

#include<iostream>

using namespace std;
unsigned int sum(int n) {
	if (n > 1)
		return n + sum(n - 1);
	else if (n == 1) {
		return 1;
	}
}

unsigned int fac(int n) {
	if (n >= 3) {
		return fac(n - 1) + fac(n - 2);
	}

	if (n == 2)
		return 1;

	if (n == 1)
		return 1;
}

unsigned int get_strlen(char *s){
	if(*s != '\0')
		return 1 + get_strlen(s + 1);
	if(*s == '\0')
		return 0;
}


//int main()
//{
//	cout << "sum :" << sum(100) << endl;
//
//	for(int i = 1;i <= 10;i++)
//		cout << "fac " << i << ":" << fac(i) << endl;
//
//	cout << "str len:" << get_strlen("1234") << endl;
//
//	return 0;
//}
