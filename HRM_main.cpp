
#include<stdio.h>
#include<string>

// importing our classes as a header file
#include "HRM.h"

using namespace std;

int main() {
    Employee* employee_list = nullptr;

    while (true) {
        int choice;
        cout << "\n--------------------------------------------" << endl;
        cout << "\tWelcome to MIKASA HRM system" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Select an action:\n" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Delete employee" << endl;
        cout << "3. Search employee" << endl;
        cout << "4. Display all employees" << endl;
        cout << "5. Display all employees' pay" << endl;
        cout << "6. Display all employees' benefits" << endl;
        cout << "7. Display all employees' performance" << endl;
        cout << "8. Quit\n" << endl;
        cout << "--------------------------------------------" << endl;
        cout << " \tEND OF MENU " << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string first_name, last_name, email, phone_number;
                float hourly_rate;
                int hours_worked;
                cout << "Enter employee details:" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "First name: ";
                cin >> first_name;
                cout << "Last name: ";
                cin >> last_name;
                cout << "Email: ";
                cin >> email;
                cout << "Phone number: ";
                cin >> phone_number;
                cout << "Hourly rate: ";
                cin >> hourly_rate;
                cout << "Hours worked: ";
                cin >> hours_worked;
                if (employee_list == nullptr) {
                    employee_list = new Employee(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked);
                } else {
                    employee_list->add_employee(new Employee(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked));
                }
                cout << "Employee added." << endl;
                break;
            }
            case 2: {
                int id;
                cout << "Enter employee ID to delete: ";
                cin >> id;
                if (employee_list != nullptr) {
                    employee_list->delete_employee(id);
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter employee ID to search: ";
                cin >> id;
                if (employee_list != nullptr) {
                    employee_list->search_and_display_employee(id);
                }
                break;
            }
            case 4: {
                if (employee_list != nullptr) {
                    employee_list->display_employees();
                }
                break;
            }
            case 5: {
                int id;
                string first_name, last_name, email, phone_number;
                float hourly_rate;
                int hours_worked;
                cout << "Enter employee details:" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "First name: ";
                cin >> first_name;
                cout << "Last name: ";
                cin >> last_name;
                cout << "Email: ";
                cin >> email;
                cout << "Phone number: ";
                cin >> phone_number;
                cout << "Hourly rate: ";
                cin >> hourly_rate;
                cout << "Hours worked: ";
                cin >> hours_worked;
                Payroll* payroll_list = nullptr;
                if (payroll_list == nullptr) {
                    payroll_list = new Payroll(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked);
                } else {
                    payroll_list->add_employee(new Payroll(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked));
                }
                payroll_list->display_employees_pay();
                delete payroll_list;
                break;
            }
            case 6: {
                int id;
                string first_name, last_name, email, phone_number;
                float hourly_rate;
                int hours_worked;
                cout << "Enter employee details:" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "First name: ";
                cin >> first_name;
                cout << "Last name: ";
                cin >> last_name;
                cout << "Email: ";
                cin >> email;
                cout << "Phone number: ";
                cin >> phone_number;
                cout << "Hourly rate: ";
                cin >> hourly_rate;
                cout << "Hours worked: ";
                cin >> hours_worked;
                Benefits* benefits_list = nullptr;
                if (benefits_list == nullptr) {
                    benefits_list = new Benefits(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked);
                } else {
                    benefits_list->add_employee(new Benefits(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked));
                }
                benefits_list->display_employees_benefits();
                delete benefits_list;
                break;
            }
            case 7: {
                int id;
                string first_name, last_name, email, phone_number;
                float hourly_rate;
                int hours_worked;
                cout << "Enter employee details:" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "First name: ";
                cin >> first_name;
                cout << "Last name: ";
                cin >> last_name;
                cout << "Email: ";
                cin >> email;
                cout << "Phone number: ";
                cin >> phone_number;
                cout << "Hourly rate: ";
                cin >> hourly_rate;
                cout << "Hours worked: ";
                cin >> hours_worked;
                Performance* performance_list = nullptr;
                if (performance_list == nullptr) {
                    performance_list = new Performance(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked);
                } else {
                    performance_list->add_employee(new Performance(id, first_name, last_name, email, phone_number, hourly_rate, hours_worked));
                }
                performance_list->display_employees_performance();
                delete performance_list;
                break;
            }
            case 8: {
                cout << "Goodbye!\n" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }
}
