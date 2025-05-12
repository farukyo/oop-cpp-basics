#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	static int nextId; // Static counter for the next available ID
	int id;			   // Instance-specific ID
	int salary;
	string school;

public:
	string name;
	int age;

	// Declare operator<< as a friend function
	friend ostream &operator<<(ostream &ekran, Employee &x);

	// Default constructor - inline
	Employee() : salary(0), school("unknown"), name("unknown"), age(0)
	{
		id = nextId++; // Assign unique ID and increment the static counter
		cout << "Default Employee created. ID: " << id << endl;
	}

	// Parameterized constructor declaration (ID removed from parameters)
	Employee(int salary, string name, int age, string school);

	// Copy constructor declaration
	Employee(const Employee &other);
	Employee operator+(const Employee &other);
	// Destructor
	~Employee()
	{
		cout << "Employee died: ID: " << id << " Name: " << name << " Age: " << age << " School: " << school << " Salary: " << salary << endl;
	}

	// Example of a member function (optional)
	void display() const
	{ // Added const as it doesn't modify members
		cout << "ID: " << id << ", Name: " << name << ", Age: " << age
			 << ", Salary: " << salary << ", School: " << school << endl;
	}

	// Static member function to get the next ID (optional, for info)
	static int getNextId()
	{
		return nextId;
	}

	Employee combineSalary(const Employee &other);
};

// Initialize static member outside the class
int Employee::nextId = 1001;

// Parameterized constructor definition (ID removed from parameters)
Employee::Employee(int salary, string name, int age, string school)
	: salary(salary), school(school), name(name), age(age)
{
	id = nextId++; // Assign unique ID and increment the static counter
	cout << "Employee created => ID: " << id << " Name: " << name << " Age: " << age << " Salary: " << salary << " School: " << school << endl;
}

// Copy constructor definition
Employee::Employee(const Employee &other)
	: salary(other.salary), school(other.school), name(other.name), age(other.age)
{
	id = nextId++; // Assign a *new* unique ID for the copy
	cout << "Employee copied => New ID: " << id << " Copied Name: " << name << endl;
}

// combined employee maker
// Creates a new Employee with combined salary.
// Name, age, and school are taken from the *this* object.
Employee Employee::combineSalary(const Employee &other)
{
	int s_new;
	s_new = salary + other.salary;
	// Returns a new Employee instance with a new ID
	return Employee(s_new, name, age, school);
}

// Overloaded addition operator
// Creates a new Employee with combined salary.
// Name, age, and school are taken from the *left-hand side* object (*this*).
Employee Employee::operator+(const Employee &other)
{
	cout << "+ operator called!" << endl; // Changed message slightly for clarity
	// Returns a new Employee instance with a new ID
	return Employee(salary + other.salary, name, age, school);
}

ostream &operator<<(ostream &ekran, Employee &x)
{
	cout << "employee OUT TEST: " << endl;
	ekran << "isim: " << x.name << endl;
	ekran << "yas: " << x.age << endl;
	ekran << "okul: " << x.school << endl;
	ekran << "maas: " << x.salary << endl;
	return ekran;
}

class Teacher : public Employee
{
};

int main()
{
	cout << "Program started." << endl;
	cout << "Next available ID: " << Employee::getNextId() << endl;

	Employee emp1; // ID: 1001, Salary: 0
	cout << "Next available ID: " << Employee::getNextId() << endl;

	Employee emp2(50000, "Alice", 30, "University A"); // ID: 1002, Salary: 50000
	cout << "Next available ID: " << Employee::getNextId() << endl;

	Employee emp3 = emp2; // ID: 1003, Salary: 50000 (Copy of emp2 with new ID)
	cout << "Next available ID: " << Employee::getNextId() << endl;

	cout << "\nDisplaying employee info:" << endl;
	emp1.display();
	emp2.display();
	emp3.display();

	cout << "\nCombining salaries (emp2 + emp3):" << endl;
	// emp4 gets salary = emp2.salary + emp3.salary = 50000 + 50000 = 100000
	// emp4 gets name, age, school from emp2 ("Alice", 30, "University A")
	// emp4 gets ID: 1004
	Employee emp4 = emp2.combineSalary(emp3);
	cout << "Next available ID: " << Employee::getNextId() << endl;

	cout << "\nDisplaying combined employee info (emp4):" << endl;
	emp4.display();

	cout << "\nAdding salaries using operator+ (emp4 + emp3):" << endl;
	// emp5 gets salary = emp4.salary + emp3.salary = 100000 + 50000 = 150000
	// emp5 gets name, age, school from emp4 ("Alice", 30, "University A")
	// emp5 gets ID: 1005
	Employee emp5 = emp4 + emp3;
	cout << "Next available ID: " << Employee::getNextId() << endl; // Should be 1006 now

	cout << "\nDisplaying added employee info (emp5):" << endl;
	emp5.display(); // Display emp5 to see the result

	cout << emp5;

	cout << "\nProgram finished." << endl;
	// Destructors will be called automatically here for emp5, emp4, emp3, emp2, emp1
	return 0;
}