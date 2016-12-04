#include <string>
#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

class A {
public:
	void PrintMsg() {
		cout << "A tells a story.\n";
		AddToStory();
	}
	void DoAction() {Action();}
private:
	virtual void Action() {cout << "Action of A\n";}
	virtual void AddToStory() {return;}
};
class B: public A {
private:
	void Action() {cout << "Action of B\n";}
	void AddToStory() {
		cout << "B wants to tell also!\n";
	}
};

int main() {
	using std::vector;
	vector<vector<vector<vector<int>>>> CrazyThing;
	int AnotherCrazyThing[4][4][4][4][4][4];
	A a;
	a.DoAction();
	a.PrintMsg();
	B b;
	b.DoAction();
	b.PrintMsg();
	auto a1 = std::make_unique<A>();
	a1->DoAction();
	a1->PrintMsg();
	auto a2 = std::make_unique<B>();
	a2->DoAction();
	a2->PrintMsg();	
}