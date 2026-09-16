#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>

using namespace std;

class LedgerEntry
{
private:
    string description;
    double* amounts;
    int days;

    static int totalEntries;

public:

    // 1. Constructor
    LedgerEntry(const string& desc, int d)
    {
        description = desc;
        days = d;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = 0.0;
        }

        totalEntries++;

        cout << "Ledger Created: "
             << description << " (" << days << " days)"
             << endl;
    }

    // 2. Copy Constructor
    LedgerEntry(const LedgerEntry& other)
    {
        description = other.description;
        days = other.days;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = other.amounts[i];
        }

        totalEntries++;
    }

    // 3. Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept
    {
        description = move(other.description);
        days = other.days;
        amounts = other.amounts;

        other.amounts = nullptr;
        other.days = 0;

        totalEntries++;

        cout << "Move Constructor: Ownership transferred."
             << endl;
    }

    // 4. Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other)
    {
        if (this != &other)
        {
            delete[] amounts;

            description = other.description;
            days = other.days;

            amounts = new double[days];

            for (int i = 0; i < days; i++)
            {
                amounts[i] = other.amounts[i];
            }
        }

        return *this;
    }

    // 5. Move Assignment Operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept
    {
        if (this != &other)
        {
            delete[] amounts;

            description = move(other.description);
            amounts = other.amounts;
            days = other.days;

            other.amounts = nullptr;
            other.days = 0;

            cout << "Move Assignment: Ownership transferred."
                 << endl;
        }

        return *this;
    }

    // 6. Destructor
    ~LedgerEntry()
    {
        delete[] amounts;
        totalEntries--;

        cout << "Destructor: "
             << description << " destroyed"
             << endl;
    }

    // 7. Addition Operator
    LedgerEntry operator+(const LedgerEntry& other) const
    {
        LedgerEntry result("Combined", days);

        for (int i = 0; i < days; i++)
        {
            result.amounts[i] =
                amounts[i] + other.amounts[i];
        }

        return result;
    }

    // 8. Equality Operator
    bool operator==(const LedgerEntry& other) const
    {
        return getTotal() == other.getTotal();
    }

    // 9. Greater Than Operator
    bool operator>(const LedgerEntry& other) const
    {
        return getTotal() > other.getTotal();
    }

    // 10. Non-const Subscript Operator
    double& operator[](int index)
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Invalid Index");
        }

        return amounts[index];
    }

    // 11. Const Subscript Operator
    const double& operator[](int index) const
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Invalid Index");
        }

        return amounts[index];
    }

    // 12. Calculate Total
    double getTotal() const
    {
        double total = 0.0;

        for (int i = 0; i < days; i++)
        {
            total += amounts[i];
        }

        return total;
    }

    // 13. Check if empty
    bool isEmpty() const
    {
        return amounts == nullptr;
    }

    // 14. Static function
    static int getTotalEntries()
    {
        return totalEntries;
    }

    // 15. Stream insertion operator
    friend ostream& operator<<(ostream& out,
                               const LedgerEntry& entry);

    // 16. Stream extraction operator
    friend istream& operator>>(istream& in,
                               LedgerEntry& entry);
};


// Static member definition
int LedgerEntry::totalEntries = 0;


// Stream insertion operator <<
ostream& operator<<(ostream& out,
                    const LedgerEntry& entry)
{
    out << entry.description << " : [";

    for (int i = 0; i < entry.days; i++)
    {
        out << entry.amounts[i];

        if (i < entry.days - 1)
        {
            out << ", ";
        }
    }

    out << "] Total: "
        << entry.getTotal();

    return out;
}


// Stream extraction operator >>
istream& operator>>(istream& in,
                    LedgerEntry& entry)
{
    in >> entry.description;

    for (int i = 0; i < entry.days; i++)
    {
        in >> entry.amounts[i];
    }

    return in;
}


int main()
{
    // January
    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200.50;
    jan[1] = 3400.00;
    jan[2] = 800.75;
    jan[3] = 2100.00;
    jan[4] = 650.25;


    // February
    LedgerEntry feb("February Sales", 5);

    feb[0] = 900.00;
    feb[1] = 2200.50;
    feb[2] = 1750.00;
    feb[3] = 3000.00;
    feb[4] = 475.50;


    // Display
    cout << jan << endl;
    cout << feb << endl;


    // Addition
    LedgerEntry combined = jan + feb;

    cout << "Combined: "
         << combined << endl;


    // Comparison
    cout << "Jan == Feb : "
         << (jan == feb ? "Yes" : "No")
         << endl;

    cout << "Jan > Feb : "
         << (jan > feb ? "Yes" : "No")
         << endl;


    // Move Constructor
    LedgerEntry moved = move(jan);

    cout << "After move, jan is empty: "
         << (jan.isEmpty() ? "YES" : "NO")
         << endl;

    cout << "Moved entry: "
         << moved << endl;


    // Move Assignment
    LedgerEntry q1("Q1 Total", 5);

    q1 = move(feb);

    cout << "Q1: "
         << q1 << endl;


    // Static member
    cout << "Live LedgerEntry objects: "
         << LedgerEntry::getTotalEntries()
         << endl;


    return 0;
}