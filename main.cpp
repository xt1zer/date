#include "Employee.h"
#include "Date/Date.h"
#include <iostream>
using std::cout, std::endl;

int main() {
    Date today(2019, 2, 21);

    Employee t;
    Employee trainee("Daniel", "White", "IT specialist", Date(1998, 12, 18), Date(2016, 12, 18), 15);
    Employee test(trainee);
    Employee economist("Garry", "Hanson", "Economist", Date(1993, 5, 3), Date(2003, 9, 8), 12);
    Employee scientist("Melody", "Brook", "Scientist", Date(1995, 10, 15), Date(2017, 4, 11), 18);

    Employee arr[5]{trainee, test, economist};
    arr[3] = scientist;
    arr[4] = Employee();

    arr[2].print_info();
    
//    test.print_info();
    cout << arr[1].compute_experience(today) << endl;
    cout << scientist.compute_age(today) << endl;
    economist.set_salary_by_exp(today);
    economist.print_info();
    return 0;
}
