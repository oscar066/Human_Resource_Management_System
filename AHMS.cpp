#include <iostream>
#include <string>
using namespace std;

class managePayroll
{
	private:
	    int empSalary;
	    int empId;
	    string empAddress;
	    string empFirstName;
	    string empLastName;

	public:
	    managePayroll(int salary, int ID, string Address, string firstName, string lastName);
	
	    void setempSalary(int salary)
	    {
	        empSalary = salary;
	    }
	
	    int getempSalary()
	    {
	        return empSalary;
	    }
	
	    void setempId(int ID)
	    {
	        empId = ID;
	    }
	
	    int getempId()
	    {
	        return empId;
	    }
	
	    void setempAddress(string Address)
	    {
	        empAddress = Address;
	    }
	
	    string getempAddress()
	    {
	        return empAddress;
	    }
	
	    void setempFirstName(string firstName)
	    {
	        empFirstName = firstName;
	    }
	
	    string getempFirstName()
	    {
	        return empFirstName;
	    }
	
	    void setempLastName(string lastName)
	    {
	        empLastName = lastName;
	    }
	
	    string getempLastName()
	    {
	        return empLastName;
	    }
	
	    string getempName()
	    {
	        return empFirstName + " " + empLastName;
	    }
};

managePayroll::managePayroll(int salary, int ID, string Address, string firstName, string lastName)
{
    setempSalary(salary);
    setempId(ID);
    setempAddress(Address);
    setempFirstName(firstName);
    setempLastName(lastName);

    cout << "Employee Info:" << endl;
    cout << "Name: " << getempName() << endl;
    cout << "ID: " << getempId() << endl;
    cout << "Salary: " << getempSalary() << endl;
    cout << "Address: " << getempAddress() << endl;
}

int main()
{
    int salary, ID;
    string Address, firstName, lastName;

    cout << "Enter the employee's Salary : \n";
    cin >> salary;

    cout << "Enter the employee's Id : \n";
    cin >> ID;

    cout << "Enter the employee's Address : \n";
    cin >> Address;

    cout << "Enter the employee's First Name : \n";
    cin >> firstName;

    cout << "Enter the employee's Last Name : \n";
    cin >> lastName;

    managePayroll employee(salary, ID, Address, firstName, lastName);

    return 0;
}


