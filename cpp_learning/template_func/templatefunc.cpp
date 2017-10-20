#include "stdafx.h"

class value
{
private:
	int mi;

public:
	value(int i)
	{
		printf("i = %d\n", i);
		mi = i;	
	}

	int getmi()
	{
		return mi;
	}

	~value()
	{
		printf("program is over.\n");
	}

};

int main()
{
	value a(5);

	printf("the value a = %d.",a.getmi());

    return 0;
}

