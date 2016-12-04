#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <bitset>
#include <cmath> 

const double EPSILON = 0.001;


int main()
{
	double a = 10.001100110001;
        double b = 10.001100110010;

	long a1;
	long b1;

	bool result  = false;

	memcpy(&a1, &a, sizeof(double));
	memcpy(&b1, &b, sizeof(double));

	std::bitset<sizeof(double)*8> a2(a1);
	std::bitset<sizeof(double)*8> b2(b1);

	std::cout << "Size of double: " << sizeof(double) << "\n";
	std::cout << "Size of long: " << sizeof(long) << "\n";

	std::cout << "Double floating point numbers to compare: \n";
	std::cout << a2 << "\n";
	std::cout << b2 << "\n";
		

	long res = a1 ^ b1; // bitwise XOR

	std::bitset<sizeof(double)*8> res1(res);
	std::cout << "result of bitwise XOR: \n";
	std::cout << res << "\n";
	
	if (res == 0)
		result = true;
	else
		result = false;
	std::cout << "Comparing two doubles, the XOR way!\n";
	std::cout << "the result is: " << result << "\n";

	std::cout << "Comparing two doubles, the standard way (== operator)!\n";
	result = a == b;
	std::cout << "the result is: " << result << "\n";

	std::cout << "Comparing two doubles, the epsilon comparison!\n";
	result = std::abs(a - b) < EPSILON;
	std::cout << "the result is: " << result << "\n";

	std::cout << "Comparing two doubles, the epsilon comparison (XOR realised)!\n";
	std::bitset<sizeof(double)*4> a3(a1 >> 8*4);
	std::bitset<sizeof(double)*4> b3(b1 >> 8*4);
	
	std::cout << a3 << "\n";
	std::cout << b3 << "\n";

	res = a3.to_ulong() ^ b3.to_ulong(); // bitwise XOR
	if (res == 0)
		result = true;
	else
		result = false;
	std::cout << "the result is: " << result << "\n";
	
	

	return 0;
}
