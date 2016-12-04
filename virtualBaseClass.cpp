#include <iostream>

class Firearm
{
public:
	virtual void fire() const {std::cout << "Bang!" << std::endl;};
	virtual void reload() {std::cout << "Reloaded!" << std::endl;};
	virtual ~Firearm() {};
};

class Pistol: public virtual Firearm
{
public:
	virtual void fire() const override {std::cout << "Piu!" << std::endl;};
	~Pistol() {};
};

class MachineGun: public virtual Firearm
{
public:
	virtual void fire() const override {std::cout << "Bang, Bang! Bang!" << std::endl;};
	~MachineGun() {};
};

class MachinePistol: public Pistol, public MachineGun
{
public:
	virtual void fire() const override {std::cout << "Piu, Piu! Piu!" << std::endl;};
	~MachinePistol() {};
};

template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int add(const int& a,const int& b) {
	return a+b;
}


int main() {
	MachinePistol gun;
	gun.reload();
	gun.fire();

	int a = 5;
	int b = 10;
	
	int* tmp = nullptr;
	delete tmp;
	swap (a, b);
	std::cout << add(2, 5) << std::endl;
	
	return 0;
}
