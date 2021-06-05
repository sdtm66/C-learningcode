#include "P50_P55_function.h"
using namespace std;
extern int a;
extern int b;

void swap(int, int)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}