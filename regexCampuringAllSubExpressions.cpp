#include <string>
#include <iostream>
#include <regex>
using namespace std;
 
int main() {
	std::regex reg_expr(R"(\([A-Z],[A-Z]\)*)");
	string input("(A,B) (C,D) (F,W) (G,K) (R,M)");
	for(std::sregex_iterator i = std::sregex_iterator(input.begin(), input.end(), reg_expr);
        i != std::sregex_iterator();
        ++i)
    {
        std::cout << (*i).str() << std::endl;
    }
	return 0;
}