#include "stdafx.h"
#include "Operator.h"

int main()
{
	Operator op;
	double r = 0;

	op.setOperator('+');
	op.setParameter(9, 3);

	if (op.result(r))
	{
		printf("r = %lf\n", r);
	}
	else
	{
		printf("Calculate error!\n");
	}

	return 0;
}
