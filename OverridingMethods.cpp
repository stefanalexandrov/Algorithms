#include <iostream>
#include <typeinfo>

class AV {
public:
	AV() {
		std::cout << "AV's constructor ()"  << std::endl;
	};
	AV(int n): m_num(n) {
		std::cout << "AV's constructor (int)"  << std::endl;
	};
	AV(char n): AV(int(n))  {
		std::cout << "AV's constructor (char)" << std::endl;
	};
	virtual void methodOfAV() const;
	virtual void anotherMethodOfAV() const;	
	static void IamStatic() {std::cout << "I am static of AV!" << std::endl;};
private:
	virtual std::string modifyOutput() const {return std::string("A modification");}; 
	int m_num;
};

void AV::methodOfAV() const {
	std::cout << "method of AV is called!"<< modifyOutput() << std::endl;
}
void AV::anotherMethodOfAV() const {
	std::cout << "another method of AV is called!" <<  modifyOutput() << std::endl;
}

class BV: public AV {
public:
	using AV::AV;
	BV(): m_num(1.1) {
		std::cout << "BV's constructor ()" << std::endl;
	};
	BV(double n): m_num(n) {
		std::cout << "BV's constructor (double)" << std::endl;
	};
	BV(long n): AV(int(n)) {
		std::cout << "BV's constructor (long)" << std::endl;
	};
	virtual void methodOfAV() const override;
	double getValue() const {return m_num;};
	static void IamStatic() {std::cout << "I am static of BV!" << std::endl;};
private:
	virtual std::string modifyOutput() const override {return std::string("B modification");}; 
	double m_num;
};

void BV::methodOfAV() const {
	std::cout << "method of BV is called!" << std::endl;
	AV::methodOfAV();
}

class A {
	public:
		void methodOfA() const;	
	private:
};

void A::methodOfA() const {
	std::cout << "method of A is called!" << std::endl;
}

class B: public A {
	public:
		void methodOfA() const;
	private:
};

void B::methodOfA() const {
	std::cout << "method of B is called!" << std::endl;
}




int main()
{
	std::cout << "BV is constructed!" << std::endl;
	BV bv;
	std::cout << "AV is constructed!" << std::endl;
	AV av;
	std::cout << "BV's m_num: " << bv.getValue() << std::endl;


	std::cout << "BV is constructed using AV's int constructor!" << std::endl;
	BV bv1(5);
	std::cout << "AV is constructed using AV's int constructor!" << std::endl;
	AV av1(4);
	std::cout << "BV's m_num: " << bv1.getValue() << std::endl;


	std::cout << "calling static method of AV from AV! \n";
	av.IamStatic();
	std::cout << "calling static method of BV from BV! \n";
	bv.IamStatic();
	std::cout << "calling static method of AV from BV! \n";
	bv.IamStatic();
		

	AV* pav= &bv;
	pav->methodOfAV();
	pav->anotherMethodOfAV();
	pav = &av; 
	pav->methodOfAV();
	pav->anotherMethodOfAV();

	B b;
	A a;
	
	b.methodOfA();
	A a1 = b;
	a1.methodOfA();

	std::cout << "Size of B object: " << sizeof(B) << std::endl;
	std::cout << "Size of A object: " << sizeof(A) << std::endl;
	std::cout << "Size of BV object: " << sizeof(BV) << std::endl;
	std::cout << "Size of AV object: " << sizeof(AV) << std::endl;
	std::cout << typeid(pav).name() << std::endl;
	std::cout << "Pointer size: " << sizeof(pav) << std::endl;
	std::cout << "Long Integer size: " << sizeof(long int) << std::endl;
	std::cout << "Long Double size: " << sizeof(long double) << std::endl;

	return 0;
}
