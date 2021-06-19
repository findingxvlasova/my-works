#include <iostream>
#include <ostream>
#include <istream>
//#include "Header.h"
using namespace std;

class Types
{

	friend	ostream& operator<<(ostream& out, Types& obj);
	friend istream& operator>>(istream& in, Types& obj);
private:
	int Int;
	double Double;
	bool Bool;
};


ostream& operator<<(ostream& out, Types& obj)
{
	out << "int: " << obj.Int << "\ndouble: " << obj.Double << "\nbool: " << obj.Bool << "\n";
	return out;
}


istream& operator>>(istream& in, Types& obj)
{
	in >> obj.Int;
	in >> obj.Double;
	in >> obj.Bool;
	return in;
}


int main()
{

	Types obj1;
	cin >> obj1;
	cout << obj1;
}

