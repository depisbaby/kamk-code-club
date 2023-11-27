#include <iostream>
#include "House.h"
#include "Methodi.h"


int main()
{
    std::cout << "Hello World!\n";
    House house;
    House* pHouse = &house;
    Methodi m;

    int i = 0;
    int* pI = &i;

    m.MethodB(pHouse, pI);
}


