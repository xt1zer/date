#include "Employee.h"
#include <iostream>
using std::cout, std::endl;

Employee::Employee() {
    this->name = new String("");
    this->surname = new String("");
    this->position = new String("");
}

Employee::Employee(const String & name, const String & surname, const String & position, const Date & birthDate, const Date & employmentDate, const float & salary) {
    this->name = new String(name);
    this->surname = new String(surname);
    this->position = new String(position);

    this->birthDate = birthDate;
    this->employmentDate = employmentDate;

    this->salary = salary;
}

Employee::Employee(const Employee & copy) {
    this->name = new String(*copy.name);
    this->surname = new String(*copy.surname);
    this->position = new String(*copy.position);

    this->birthDate = copy.birthDate;
    this->employmentDate = copy.employmentDate;

    this->salary = copy.salary;
}

Employee::~Employee() {
    delete name; delete surname; delete position;
    name = surname = position = nullptr;
    birthDate = Date();
    employmentDate = Date();
    salary = 0.0;
}

void Employee::print_info() const {
    cout << "\t Full name: "; name->print(); cout << " "; surname->print(); cout << " \n";
    cout << "\t Position: "; position->print(); cout << endl;
    cout << "\t Date of birth: "; birthDate.print_date();
    cout << "\t Date of employment: "; employmentDate.print_date();
    cout << "\t Salary: " << salary << endl;
}

void Employee::set_position(const String & position) { *this->position = position; }

void Employee::set_salary(const float & salary) { this->salary = salary; }

const short int Employee::compute_age(const Date & today) const {
    if (today.correct_date() && today > birthDate) {
        return (unsigned short int)(count_days_between_dates(birthDate, today) / 365);
    }

    else {
        std::cout << "\t Wrong current date! \n";
        return -1;
    }
}

const short int Employee::compute_experience(const Date & today) const {
    if (today.correct_date() && today > employmentDate) {
        return (unsigned short int)(count_days_between_dates(employmentDate, today) / 365);
    }

    else {
        std::cout << "\t Wrong current date! \n";
        return -1;
    }
}

void Employee::set_salary_by_exp(const Date & today) {
    const short int experience = compute_experience(today);

    if (experience == -1)
        return;

    if(experience >= 15 && experience < 20)
        salary += salary / 100 * 3;

    else if (experience >= 20 && experience < 25)
        salary += salary / 100 * 5;

    else if (experience >= 25 && experience < 30)
        salary += salary / 100 * 10;

    else if (experience >= 30)
        salary += salary / 100 * 15;
}
