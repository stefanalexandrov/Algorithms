#include <regex>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	regex reg_expr(R"((\([A-Z],[A-Z]\))(?:\s(\([A-Z],[A-Z]\)))*)");
	//regex reg_expr("(\\([A-Z],[A-Z]\\))(?:\\s(\\([A-Z],[A-Z]\\)))*\\s(\\([A-Z],[A-Z]\\))");
	smatch sm;
	string input("(A,B) (C,D) (F,W) (G,K) (R,M)");
	//string input("(A,B) (C,D) (F,W)");
	if (regex_match(input, sm, reg_expr)) {
		cout << "true\n";
		cout << sm.size() << "\n";
		for (int i = 0; i < sm.size(); i++) {
			//if (sm[i].length())
				cout << "submatch number " << i << ": " << sm[i].str() << '\n';
		}
	} else
		cout << "false";
	return 0;
}