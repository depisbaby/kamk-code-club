#include <iostream>
#include <vector>
#include "Mem.h"
#include <time.h>
#include <ctime>

std::vector<Mem*> memories;
void CreateNewMemory() 
{
    int bsX = rand() % 100;
    int bsY = rand() % 100;
    Mem* pMem = new Mem(bsX, bsY);
    memories.push_back(pMem);
}

int main()
{
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < 1000000; i++)
    {
        CreateNewMemory();
    }
    
    for (size_t i = 0; i < memories.size(); i++)
    {
        std::cout << "GameObject " << "[" << i << "] [" << memories[i]->positionX << "," << memories[i]->positionY << "]" << "\n";
    }
    std::cout << memories.size() << "\n";
}

