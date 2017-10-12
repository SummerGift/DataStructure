#include "stdafx.h"
#include "Operator.h"

bool Operator::setOperator(char op)
{
	bool ret = false;

	if ((op == '+') || (op == '-') || (op == '*') || (op == '/'))
	{
		ret = true;
		mOp = op;
	}
	else
	{
		mOp = '\0';
	}

	return ret;
}

void Operator::setParameter(double p1, double p2)
{
	mP1 = p1;
	mP2 = p2;
}

bool Operator::result(double& r)
{
	bool ret = true;

	switch (mOp)
	{
	case '/':
		if ((-0.000000001 < mP2) && (mP2 < 0.000000001))
		{
			ret = false;
		}
		else
		{
			r = mP1 / mP2;
		}
		break;
	case '+':
		r = mP1 + mP2;
		break;
	case '*':
		r = mP1 * mP2;
		break;
	case '-':
		r = mP1 - mP2;
		break;
	default:
		ret = false;
		break;
	}

	return ret;
}
