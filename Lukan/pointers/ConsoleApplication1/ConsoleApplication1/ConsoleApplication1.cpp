

#include <iostream>


class BigClass {
public:
	int i;
	std::string sArray[100];
};

class MyClass
{
public:
	MyClass();
	~MyClass();
	void MethodA(BigClass* obj);
	void MethodB(BigClass &obj);

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

void MyClass::MethodA(BigClass* obj) //Pass by pointer
{
	obj->i += 1;

	if (obj->i >= 5000)return;

	std::cout << "On the loop number: " << obj->i << "\n";

	MethodA(obj);
}

void MyClass::MethodB(BigClass &obj) //Pass by reference
{
	obj.i += 1;

	if (obj.i >= 5000) return;

	std::cout << "On the loop number: " << obj.i << "\n";

	MethodB(obj);
}


int main()
{
    using namespace std;

	int i = 0;
	int* pI = &i;

	MyClass myClass;
	MyClass* pMyClass = &myClass;

	BigClass obj;
	BigClass* pObj = &obj;
	
	pObj->i = 0;

	pMyClass->MethodA(pObj);

	pMyClass->MethodB(obj);



    cout << "";




}

