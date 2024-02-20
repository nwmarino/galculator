#pragma once
#include <string>
using namespace std;
namespace galculator
{
    class Grade
    {
    public:
        string tag;
        int value;
        double weighting;

        Grade(string tag, int value, double weighting);
        double resolve();
    };
}