// smartpointer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

namespace Summerlib
{





}

void fn();
void main()
{
	fn();
	fn();
	fn();
}
void fn()
{
	static int n = 10;
	printf("n = %d\n",n);

	n++;
}