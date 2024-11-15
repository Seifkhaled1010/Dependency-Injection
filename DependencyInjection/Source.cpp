#include <iostream>
#include <list>
using namespace std;


class Employee
{
public:
	Employee(int ID, const char * name, const char * department)
	{
		this->ID = ID;
		strcpy_s(this->Name, name);
		strcpy_s(this->Department, department);
	}

	int ID;
	char Name[250];
	char Department[100];
};

//#define BEFORE

#ifdef BEFORE
class EmployeeDAL
{
public:
	list<Employee> SelectAllEmployees()
	{
		Employee emp1(1, "Pranaya", "IT");
		Employee emp2(2, "Kumar", "HR");
		Employee emp3(3, "Rout", "Payroll");
		list<Employee> employees;
		employees.push_back(emp1);
		employees.push_back(emp2);
		employees.push_back(emp3);

		return employees;
	}
};

class EmployeeBL
{
private:
	EmployeeDAL employeeDAL;
public:
	list<Employee> GetAllEmployees()
	{
		return employeeDAL.SelectAllEmployees();
	}
};
#else
class IEmployeeDAL
{
public:
	virtual list<Employee> SelectAllEmployees() = 0;
};

class EmployeeDAL : public IEmployeeDAL
{
public:
	virtual list<Employee> SelectAllEmployees()
	{
		Employee emp1(1, "Pranaya", "IT");
		Employee emp2(2, "Kumar", "HR");
		Employee emp3(3, "Rout", "Payroll");
		list<Employee> employees;
		employees.push_back(emp1);
		employees.push_back(emp2);
		employees.push_back(emp3);

		return employees;
	}
};

class TEmployeeDAL : public IEmployeeDAL
{
public:
	virtual list<Employee> SelectAllEmployees()
	{
		return list<Employee>();
	}
};

class EmployeeBL
{
private:
	IEmployeeDAL *employeeDAL;
public:
	EmployeeBL(IEmployeeDAL * employeeDAL)
	{
		this->employeeDAL = employeeDAL;
	}
	
	list<Employee> GetAllEmployees()
	{
		return employeeDAL->SelectAllEmployees();
	}
};
#endif