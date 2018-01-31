#pragma once
#ifndef _OPERATOR_H_
#define _OPERATOR_H_

class Operator
{
private:
	char mOp;
	double mP1;
	double mP2;

public:
	bool setOperator(char op);
	void setParameter(double p1, double p2);
	bool result(double& r);
};

#endif
