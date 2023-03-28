#include <iostream>
#include <string>

using namespace std;

class Employee {
  private:
    int employee_id;
    string first_name;
    string last_name;
    string email;
    string phone_number;
    float hourly_rate;
    int hours_worked;
    Employee* next_employee;
  
  public:
    Employee(int employee_id, string first_name, string last_name, string email, string phone_number, float hourly_rate, int hours_worked);
    void set_employee_id(int employee_id);
    int get_employee_id();
    void set_first_name(string first_name);
    string get_first_name();
    void set_last_name(string last_name);
    string get_last_name();
    void set_email(string email);
    string get_email();
    void set_phone_number(string phone_number);
    string get_phone_number();
    Employee* get_next_employee();
    void set_next_employee(Employee* next_employee);
    void add_employee(Employee* new_employee);
    void delete_employee(int employee_id);
    Employee* search_employee(int employee_id);
    void display_employees();
    void search_and_display_employee(int employee_id);
    void set_hourly_rate(float hourly_rate);
    float get_hourly_rate();
    void set_hours_worked(int hours_worked);
    int get_hours_worked();
};

Employee::Employee(int employee_id, string first_name, string last_name, string email, string phone_number, float hourly_rate, int hours_worked) {
  this->employee_id = employee_id;
  this->first_name = first_name;
  this->last_name = last_name;
  this->email = email;
  this->phone_number = phone_number;
  this->hourly_rate = hourly_rate;
  this->hours_worked = hours_worked;
  this->next_employee = nullptr;
}

void Employee::set_employee_id(int employee_id) {
  this->employee_id = employee_id;
}

int Employee::get_employee_id() {
  return employee_id;
}

void Employee::set_first_name(string first_name) {
  this->first_name = first_name;
}

string Employee::get_first_name() {
  return first_name;
}

void Employee::set_last_name(string last_name) {
  this->last_name = last_name;
}

string Employee::get_last_name() {
  return last_name;
}

void Employee::set_email(string email) {
  this->email = email;
}

string Employee::get_email() {
  return email;
}

void Employee::set_phone_number(string phone_number) {
  this->phone_number = phone_number;
}

string Employee::get_phone_number() {
  return phone_number;
}

void Employee::set_hourly_rate(float hourly_rate) {
  this->hourly_rate = hourly_rate;
}

float Employee::get_hourly_rate() {
  return hourly_rate;
}

void Employee::set_hours_worked(int hours_worked) {
  this->hours_worked = hours_worked;
}

int Employee::get_hours_worked() {
  return hours_worked;
}

Employee* Employee::get_next_employee() {
  return next_employee;
}

void Employee::set_next_employee(Employee* next_employee) {
  this->next_employee = next_employee;
}

void Employee::add_employee(Employee* new_employee) {
  if (next_employee == nullptr) {
    next_employee = new_employee;
  } else {
    next_employee->add_employee(new_employee);
  }
}

Employee* Employee::search_employee(int employee_id) {
  if (this->employee_id == employee_id) {
    return this;
  } else if (next_employee != nullptr) {
    return next_employee->search_employee(employee_id);
  } else {
    return nullptr;
  }
}

void Employee::search_and_display_employee(int employee_id) {
  Employee* employee = search_employee(employee_id);
  if (employee != nullptr) {
    cout << "------------------------------------------" << endl;
    cout << "EMPLOYEE FOUND " << endl;
    cout << "------------------------------------------" << endl;
    cout << "Employee found: " << endl;
    cout << "Employee ID: " << employee->employee_id << endl;
    cout << "First Name: " << employee->first_name << endl;
    cout << "Last Name: " << employee->last_name << endl;
    cout << "Email: " << employee->email << endl;
    cout << "Phone Number: " << employee->phone_number << endl;
    cout << "------------------------------------------" << endl;
    cout << "END OF SEARCH RESULTS" << endl;
    cout << "------------------------------------------\n" << endl;
    cout << endl;
  } else {
    cout << "------------------------------------------" << endl;
    cout << "Employee not found." << endl;
    cout << "------------------------------------------\n" << endl;
    cout<<endl;
  }
}


void Employee::delete_employee(int employee_id) {
  if (next_employee != nullptr) {
    if (next_employee->employee_id == employee_id) {
      Employee* temp = next_employee;
      next_employee = next_employee->next_employee;
      delete temp;
    } else {
      next_employee->delete_employee(employee_id);
    }
  }
}

void Employee::display_employees() {
  cout << "------------------------------------------" << endl;
  cout << "DISPLAYING ALL MIKASA EMPLOYEES" << endl;
  cout << "------------------------------------------" << endl;

  Employee* current_employee = this;
  while (current_employee != nullptr) {
    cout << "Employee ID: " << current_employee->employee_id << endl;
    cout << "First Name: " << current_employee->first_name << endl;
    cout << "Last Name: " << current_employee->last_name << endl;
    cout << "Email: " << current_employee->email << endl;
    cout << "Phone Number: " << current_employee->phone_number << endl;
    cout << endl;
    current_employee = current_employee->next_employee;
  }
  cout << "------------------------------------------" << endl;
  cout << "END OF EMPLOYEE LIST." << endl;
  cout << "------------------------------------------\n" << endl;
  cout << endl;
}

// Define the Payroll class
class Payroll : public Employee {
public:
    Payroll(int employee_id, string first_name, string last_name, string email, string phone_number, float hourly_rate, int hours_worked)
    : Employee(employee_id, first_name, last_name, email, phone_number, hourly_rate, hours_worked) {}

    void display_employees_pay() {
        cout << "--------------------------------------------------------------" << endl;
        cout << "    \t\tMIKASA PAYROLL DISPLAY " << endl;
        cout << "--------------------------------------------------------------" << endl;

        cout << "Employee ID\tFirst Name\tLast Name\tTotal Pay (Ksh)" << endl;
        cout<<  "-----------\t----------\t---------\t--------------" << endl;

        Employee* current_employee = this;
        while (current_employee != nullptr) {
            cout << current_employee->get_employee_id() << "\t\t" << current_employee->get_first_name() << "\t\t" << current_employee->get_last_name() <<   "\t\t" << current_employee->get_hours_worked() * current_employee->get_hourly_rate() << endl;
            current_employee = current_employee->get_next_employee();
        }
        cout << "--------------------------------------------------------------" << endl;
        cout << "    \t\tEND OF PAYROLL DISPLAY." << endl;
        cout << "--------------------------------------------------------------\n" << endl;
        cout << endl;
    }
};


// Define the Benefits class
class Benefits : public Employee {
public:
  Benefits(int employee_id, string first_name, string last_name, string email, string phone_number, float hourly_rate, int hours_worked)
    : Employee(employee_id, first_name, last_name, email, phone_number, hourly_rate, hours_worked) {}

  float calculate_benefits(int hours_worked, float hourly_rate) {
      float total_benefits = 0.0;
      if (hours_worked > 40) {
          total_benefits = (hours_worked - 40) * hourly_rate * 0.5;
      }
      return total_benefits;
  }
    
  void display_employees_benefits() {
      cout << "--------------------------------------------------------------" << endl;
      cout << "    \t\tMIKASA BENEFITS DISPLAY " << endl;
      cout << "--------------------------------------------------------------" << endl;
      cout << "Employee ID\tFirst Name\tLast Name\tBenefits (Ksh)" << endl;
      cout<<  "-----------\t----------\t---------\t--------------" << endl;
      Employee* current_employee = this;
      while (current_employee != nullptr) {
          cout << current_employee->get_employee_id() << "\t\t" << current_employee->get_first_name() << "\t\t" << current_employee->get_last_name() << "\t\t" << calculate_benefits(current_employee->get_hours_worked(),current_employee->get_hourly_rate()) << endl;
          current_employee = current_employee->get_next_employee();
      }
      cout << "--------------------------------------------------------------" << endl;
      cout << "    \t\tEND OF BENEFITS DISPLAY " << endl;
      cout << "--------------------------------------------------------------\n" << endl;
      cout << endl;
  }
};


// Define the Performance class
class Performance : public Employee {
public:
  Performance(int employee_id, string first_name, string last_name, string email, string phone_number, float hourly_rate, int hours_worked)
  : Employee(employee_id, first_name, last_name, email, phone_number, hourly_rate, hours_worked) {}

  void calculate_performance(int hours_worked){
    if (hours_worked >= 60){
       cout << "Outstanding" << endl;
    }
    else if (hours_worked >= 40){
      cout << "Above average" << endl;
    }
    else if (hours_worked == 40){
      cout << "Average" << endl;
    }
    else{
      cout << "Below average" << endl;
    }
  }

  void display_employees_performance(){
    cout << "--------------------------------------------------------------" << endl;
    cout << "    \t\tMIKASA PERFORMANCE DISPLAY " << endl;
    cout << "--------------------------------------------------------------" << endl;

    cout << "Employee ID\tFirst Name\tLast Name\tPerformance" << endl;
    cout<<  "-----------\t----------\t---------\t--------------" << endl;

    Employee* current_employee = this;
    while (current_employee != nullptr) {
      cout << current_employee->get_employee_id() << "\t\t" << current_employee->get_first_name() << "\t\t" << current_employee->get_last_name() << "\t\t";
      calculate_performance(current_employee->get_hours_worked());
      current_employee = current_employee->get_next_employee();
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "    \t\tEND OF PERFORMANCE DISPLAY " << endl;
    cout << "--------------------------------------------------------------\n" << endl;
    cout << endl;
  }
};


// Define the Attendance tracking class
//some dummy code
class Attendance{
  public:
  void track_attendance(){
    cout<<"Attendance has been tracked"<<endl;
  }
};

// Define the HR class
//some dummy code
class HR{
  public:
  void manage_employee(){
    cout<<"Employee has been managed"<<endl;
  }
};
