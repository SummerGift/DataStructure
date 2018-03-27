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

int main() {

	Operator<int> opint;
	Operator<double> opdouble;

	cout << "4 * 5 = " << opint.op(4,5) << endl;
	cout << "4.0 * 5.0 = " << opdouble.op(0.03, 0.05) << endl;
	return 0;
}

