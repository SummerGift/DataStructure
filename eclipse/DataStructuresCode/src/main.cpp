#include <iostream>

using namespace std;

template <typename T>
void Swap(T &a,T &b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T>
class Operator
{
public:
	T op(T a,T b)
	{
		return a*b;
	}
};



void demo1()
{
	throw 'c';
}


int main() {

	cout << "main begin" << endl;

	try
	{
		demo1();
	}
	catch(int i)
	{
		cout << "catch(int i)" << endl;
	}
	catch(char i)
	{
		cout << "catch(char i)" << endl;
	}
	catch(...)
	{
		cout << "catch(...)" << endl;
	}

	cout << "main end" << endl;

	return 0;
}

