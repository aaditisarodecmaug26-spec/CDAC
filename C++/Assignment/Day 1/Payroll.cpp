#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int empId;
    string name, department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;

public:

    Employee()
    {
        empId = 1001 + employeeCount;
        employeeCount++;
        isActive = true;
        grade = 'D';
        basicSalary = 10001;
    }

    void setName(const string& n)
    {
        if (!n.empty())
            name = n;
        else
            cout << "ERROR: Name cannot be empty." << endl;
    }

    void setDepartment(const string& d)
    {
        if (d == "Engineering" || d == "HR" ||
            d == "Finance" || d == "Operations")
            department = d;
        else
            cout << "ERROR: '" << d
                 << "' is not a registered department." << endl;
    }

    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
            grade = g;
        else
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D." << endl;
    }

    void setBasicSalary(double s)
    {
        if (s > 10000 && s < 500000)
            basicSalary = s;
        else
            cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000."
                 << endl;
    }

    void deactivate()
    {
        isActive = false;
    }

    int getEmpId() const { return empId; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    char getGrade() const { return grade; }
    double getBasicSalary() const { return basicSalary; }
    bool getIsActive() const { return isActive; }

    double computeAllowances() const
    {
        if (grade == 'A') return basicSalary * 0.40;
        if (grade == 'B') return basicSalary * 0.30;
        if (grade == 'C') return basicSalary * 0.20;
        return basicSalary * 0.10;
    }

    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
            return 0;
        else if (gross <= 100000)
            return (gross - 50000) * 0.10;
        else
            return 5000 + (gross - 100000) * 0.20;
    }

    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    void acceptDetails()
    {
        string n, d;
        char g;
        double s;

        cout << "\nEnter name: ";
        getline(cin >> ws, n);
        setName(n);

        cout << "Enter department: ";
        cin >> d;
        setDepartment(d);

        cout << "Enter grade: ";
        cin >> g;
        setGrade(g);

        cout << "Enter basic salary: ";
        cin >> s;
        setBasicSalary(s);
    }

    void printPayslip() const
    {
        cout << "       EMPLOYEE PAYSLIP" << endl;

        cout << "Emp ID     : " << empId << endl;
        cout << "Name       : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Grade      : " << grade << endl;
        cout << "Status     : " << (isActive ? "Active" : "Inactive") << endl;

        cout << fixed << setprecision(2);
        cout << "Basic      : Rs. " << basicSalary << endl;
        cout << "Allowance  : Rs. " << computeAllowances() << endl;
        cout << "Gross      : Rs. " << computeGrossSalary() << endl;
        cout << "Tax        : Rs. " << computeTax() << endl;
        cout << "Net Salary : Rs. " << computeNetSalary() << endl;

    }

    static int getEmployeeCount()
    {
        return employeeCount;
    }
};

int Employee::employeeCount = 0;

int main()
{
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    e3->deactivate();

    if (!e3->getIsActive())
        cout << e3->getName()
             << " is no longer active. Payroll skipped." << endl;

    cout << "Total Employees : "
         << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}