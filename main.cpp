#include <iostream>
#include "MDArray.h"
using namespace justin_su;
int main()
{
    MDArray<int>arr = {{1,2,3},{4,5,6},{7,8}};
    arr.print();
    return 0;
}
