#include "tupleToVector.h"
#include "print_ip.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char ch(-1);
	pip::PrintIP(ch); 
	cout << endl;

	short sh(0);
	pip::PrintIP(sh);
	cout << endl;

	int i(2'130'706'433);
	pip::PrintIP(i);
	cout << endl;

	long long L(8'875'824'491'850'138'409);
	pip::PrintIP(L);
	cout << endl;

	std::string str{"string"};
	pip::PrintIP(str);
	cout << endl;

	std::vector<int> v{ 0, 1, 2, 3 };
	pip::PrintIP(v);
	cout << endl;

	std::list<int> ls{ 3, 2, 1, 0 };
	pip::PrintIP(ls);
	cout << endl;

	auto t = std::make_tuple( 0, 10, 20, 30 );
	pip::PrintIP(t);
	cout << endl;

	cin.get();
	return 0;
}