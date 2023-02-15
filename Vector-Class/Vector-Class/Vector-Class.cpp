#include <iostream>
#include <vector>
#include <math.h>
//#include "Vector3.h"

int main()
{
    for (int i = -360; i <= 360; i++)
    {
        printf("%d %f\n", i, cosf(i / (atan(1.0f) * 4.0f)));
    }
    return 0;
}