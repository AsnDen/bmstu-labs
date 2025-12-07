#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct Employee {
    short unsigned int age{};
    long double salary{};
    std::string name{};
};

void showEmployee( const Employee &emp )
{
    std::cout << "Name: " << emp.name << '\n'
              << "Age: " << emp.age << '\n'
              << "Salary: " << emp.salary << '\n';
}

Employee theYoungestEmployee( const std::vector<Employee> &emps )
{
    Employee youngest{emps[0]};
    for( Employee emp : emps ) {
        if( youngest.age > emp.age ) {
            youngest = emp;
        }
    }
    return youngest;
}

Employee theOldestEmployee( const std::vector<Employee> &emps )
{
    Employee oldest{emps[0]};
    for( Employee emp : emps ) {
        if( oldest.age < emp.age ) {
            oldest = emp;
        }
    }
    return oldest;
}

long double avarageSalary( const std::vector<Employee> &emps )
{
    long double average{0};
    for( Employee emp : emps ) {
        average += emp.salary;
    }
    return average / emps.size();
}

int main()
{
    std::vector<Employee> employees{};

    size_t num_of_employees{};
    std::cout << "Number of employees: ";
    std::cin >> num_of_employees;

    for( size_t i{}; i < num_of_employees; i++ ) {
        Employee new_emp{};
        std::cout << "Enter the name, age and salary of a employee\n";
        try {
            std::cin >> new_emp.name >> new_emp.age >> new_emp.salary;
            if( ( new_emp.age > 140 ) || ( new_emp.salary < 0 ) ) {
                throw std::invalid_argument( "Incorrect values" );
            }
            employees.push_back( new_emp );
        } catch( const std::invalid_argument &e ) {
            std::cout << "Age or salary are incorrect\n"
                         "Try again";
            i--;
        }
    }

    std::cout << "------------\n";
    std::cout << "The youngest employee\n";
    showEmployee( theYoungestEmployee( employees ) );
    std::cout << "------------\n";
    std::cout << "The oldest employee\n";
    showEmployee( theOldestEmployee( employees ) );
    std::cout << "------------\n";

    std::cout << "Average salary is " << avarageSalary( employees ) << '\n';

    return 0;
}
