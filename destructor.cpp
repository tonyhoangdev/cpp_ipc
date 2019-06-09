#include <iostream>

class BaseClass {
public:
    BaseClass() {
        std::cout << "Constructor Base Class" << std::endl;
    }

    virtual ~BaseClass() {
        std::cout << "Destructor Base Class" << std::endl;
    }
};

class DerivedClass : public BaseClass {
public:
    DerivedClass() {
        std::cout << "Constructor Derived Class" << std::endl;
    }

    virtual ~DerivedClass() {
        std::cout << "Destructor Derived Class" << std::endl;
    }
};


class DerivedClass2: public DerivedClass {
public:
    DerivedClass2() {
        std::cout << "Constructor Derived Class2" << std::endl;
    }

    virtual ~DerivedClass2() {
        std::cout << "Destructor Derived Class2" << std::endl;
    }
};

int main() {
    BaseClass *base = new DerivedClass2();

    delete base;

    return 0;
}