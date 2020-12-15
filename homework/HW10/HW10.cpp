// CS 311 HW 10
// Date Conversion
// Noah Grassmeyer

#include <iostream>
#include <exception>

using namespace std;

class MonthError : public exception
{
    virtual const char* what() const throw()
    {
        return "Invalid Month.";
    }
} monthex;

class DayError : public exception
{
    virtual const char* what() const throw()
    {
        return "Invalid Day.";
    }
} dayex;

int main()
{
    try
    {
        unsigned month, day;
        unsigned days[12] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        string months[12] = { "January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December" };
        
        cout << "Please enter numerical values for a month and a day in that month separated by a space: ";
            cin >> month;
            cin >> day;

        if (month > 12)
            throw monthex;

        if (day > days[month - 1])
            throw dayex;

        cout << endl << months[month - 1] << " " << day << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}
