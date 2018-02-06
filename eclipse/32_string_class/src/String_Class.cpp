//============================================================================
// Name        : String_Class.cpp
// Author      : summergift
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

string reverse(const string& s, const char c)
{
    string ret = s;


    return ret;
}

int main()
{
	cout << "hello" <<  endl;
	string s1 = "hello";
	string s2 = "mengbaobao";
	cout << s1 + s2 <<  endl;

	string test = "we;tonight;you";
	cout << test << endl;
	cout << test.length() << endl;
	int pos = test.find(';');
	cout << pos << endl;   //1,默认从位置0（即第1个字符）开始查找
	string b = test.substr(0, pos);
	cout << b << endl;

//    cout << reverse("", ';') << endl;                 // 输出：空字符串
//    cout << reverse(";", ';') << endl;                // 输出：;
//    cout << reverse("abcde;", ';') << endl;           // 输出：edcba;
//    cout << reverse("we;tonight;you", ';') << endl;   // 输出：ew;thginot;uoy

    return 0;
}
