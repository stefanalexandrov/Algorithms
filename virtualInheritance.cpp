#include <iostream>

class A {
  public:
    A(int s) { std::cout << "A(" << s << ")\n"; ms = s; };
    int ms;
    virtual void dummy() {std::cout << "Aaaaaa!" << std::endl;};
    virtual ~A() {std::cout << "~A(" << ms << ")\n";};
};

class B1 : virtual public A {
  public:
    B1(int s1, int s2)
        : A{s1} { std::cout << "B1(" << s1 << "," << s2 << ")\n"; };
};

class B2 : virtual public A {
  public:
    B2(int s1, int s2)
        : A{s1} { std::cout << "B2(" << s1 << "," << s2 << ")\n"; };
};

class C1 : public B1, public B2 {
  public:
    C1() : B1{1,2}, B2{3,4}, A{5}  {};
};

class C2 : public B1, public B2 {
  public:
    C2() : B1(1,2), B2(3,4), A{5} {};
};

int main()
{
  {
    std::cout << "Create c1:\n";
    C1 c1;
    std::cout << "Calling A's dummy on c1: " << std::endl;
    c1.dummy();
    std::cout << "Size of c1: " << sizeof(c1) << std::endl;
  }

  {
    std::cout << "\n";
    std::cout << "Create c2:\n";
    C2 c2;
    std::cout << "Calling A's dummy on c2: " << std::endl;
    c2.dummy();
    std::cout << "Size of c2: " <<sizeof(c2) << std::endl;
  }

}
