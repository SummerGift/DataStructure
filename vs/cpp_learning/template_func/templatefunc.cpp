#include "stdafx.h"

class Test
{
private:
	int mi;
public:
	Test()
	{
		printf("create test.");

	}
	Test(int i)
	{
		mi = i;
		printf("create test.value = %d.",i);

	}

	~Test()
	{
		printf("test gone.");
	
	}

	void print()
	{
		printf("the value is %d.",mi);
	
	}


};

int main()
{
	Test(1).print();

	return 0;

}