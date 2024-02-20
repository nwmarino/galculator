#include <iostream>
#include <stack>
#include <format>
#include "Grade.cpp"
using namespace std;
using namespace galculator;

int main()
{
    stack<Grade> grades;
    cout << "GALCULATOR" << '\n';
    bool condition = true;
    while (condition)
    {
        cout << "<Q> Stops collecting grades.\n";
        cout << "<N> Input a new grade.\n";
        string input;
        cin >> input;
        if (input == "Q" || input == "q")
        {
            condition = false;
        }
        else if (input == "N" || input == "n")
        {
            string tag;
            int grade;
            double weighting;
            cout << "Provide a tag: ";
            cin >> tag;
            cout << "Provide a numeric grade: ";
            cin >> grade;
            cout << "Provide a grade weighting: ";
            cin >> weighting;
            grades.push(Grade(tag, grade, weighting));
        }
        else
        {
            cout << "That command does not exist.\n";
        };
    };
    if (grades.empty())
    {
        cout << "No grades were provided. Exiting program.\n";
        return 0;
    };
    cout << "CALCULATOR RESULTS\n";
    double grade = 0;
    double over = 0;
    double weight = 0;
    while (not grades.empty())
    {
        Grade curr = grades.top();
        grade += curr.resolve();
        over += curr.value;
        weight += curr.weighting;
        grades.pop();
        string formatted_str = format("T: {} | G: {} | W: {}%", curr.tag, \
        curr.value, (curr.weighting * 100));
        cout << formatted_str << '\n';
    };
    cout << "Current grade: " << grade / weight << '\n';
    if ((weight * 100) < 100)
    {
        double remaining_weight = 1.0 - weight;
        double goal;
        cout << "Input the grade you want: ";
        cin >> goal;
        double needed = (goal - grade) / (remaining_weight);
        cout << '\n' << "Remaining components: " << (remaining_weight * 100) << "%\n";
        cout << "Grade needed over remaining components: " << needed << '\n';
    }
    else
    {
        cout << "Weightings exceed 100%. No goal can be set.";
    };
};