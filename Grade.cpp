#include "Grade.h"
#include <string>
using namespace std;
using namespace galculator;

Grade::Grade(string tag, int value, double weighting)
{   
    Grade::tag = tag;
    Grade::value = value;
    Grade::weighting = weighting;
}

double Grade::resolve()
{
    return value * weighting;
}