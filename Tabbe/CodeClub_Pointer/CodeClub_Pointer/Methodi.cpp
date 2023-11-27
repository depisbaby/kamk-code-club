#include "Methodi.h"
#include "House.h"

void Methodi::MethodB(House* paska, int* i) 
{
    if (*i >= 10000)return;
    std::cout << "On the loop number: " << *i << "\n";

    *i += 1;
    MethodB(paska, i);
}