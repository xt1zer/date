#pragma once
#include "String/String.h"
#include "Date/Date.h"

class Employee {

private:

    String * name;
    String * surname;
    String * position;
    String * education;
    Date birthDate;
    Date employmentDate;
    float salary;

public:

    Employee();// = default;
    Employee(const String & name, const String & surname, const String & position, const String & education, const Date & birthDate, const Date & employmentDate, const float & salary);
    Employee(const Employee &);
    ~Employee();

    void print_info() const;
    void set_position(const String &);
    void set_education(const String &);
    void set_salary(const float &);
    const short int compute_age(const Date & today) const;
    const short int compute_experience(const Date & today) const;
    void set_salary_by_exp(const Date & today);

};
