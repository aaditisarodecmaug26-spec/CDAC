#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <stdexcept>
#include <ctime>

using namespace std;

namespace LibrarySystem
{

class LibraryException : public exception
{
protected:
    string message;

public:
    LibraryException(string msg)
    {
        message = msg;
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class BookNotFoundException : public LibraryException
{
public:
    BookNotFoundException(string msg) : LibraryException(msg) {}
};

class MemberNotFoundException : public LibraryException
{
public:
    MemberNotFoundException(string msg) : LibraryException(msg) {}
};

class BookNotAvailableException : public LibraryException
{
public:
    BookNotAvailableException(string msg) : LibraryException(msg) {}
};

class MaxBooksExceededException : public LibraryException
{
public:
    MaxBooksExceededException(string msg) : LibraryException(msg) {}
};


class Person
{
protected:
    int id;
    string name;
    string phone;

public:
    Person()
    {
        id = 0;
        name = "";
        phone = "";
    }

    Person(int id, string name, string phone)
    {
        this->id = id;
        this->name = name;
        this->phone = phone;
    }

    virtual void displayInfo() const = 0;

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    string getPhone() const
    {
        return phone;
    }

    virtual ~Person() {}
};


class Member : public Person
{
private:
    int bookCount;
    int* issuedBookIds;

public:
    Member() : Person()
    {
        bookCount = 0;
        issuedBookIds = new int[5];

        for (int i = 0; i < 5; i++)
            issuedBookIds[i] = 0;
    }

    Member(int id, string name, string phone)
        : Person(id, name, phone)
    {
        bookCount = 0;
        issuedBookIds = new int[5];

        for (int i = 0; i < 5; i++)
            issuedBookIds[i] = 0;
    }

    Member(const Member& other)
        : Person(other.id, other.name, other.phone)
    {
        bookCount = other.bookCount;

        issuedBookIds = new int[5];

        for (int i = 0; i < 5; i++)
            issuedBookIds[i] = other.issuedBookIds[i];
    }

    Member& operator=(const Member& other)
    {
        if (this != &other)
        {
            id = other.id;
            name = other.name;
            phone = other.phone;
            bookCount = other.bookCount;

            delete[] issuedBookIds;
            issuedBookIds = new int[5];

            for (int i = 0; i < 5; i++)
                issuedBookIds[i] = other.issuedBookIds[i];
        }

        return *this;
    }

    ~Member()
    {
        delete[] issuedBookIds;
    }

    void addBook(int bookId)
    {
        if (bookCount >= 5)
            throw MaxBooksExceededException("Maximum 5 books allowed.");

        issuedBookIds[bookCount] = bookId;
        bookCount++;
    }

    void removeBook(int bookId)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (issuedBookIds[i] == bookId)
            {
                for (int j = i; j < bookCount - 1; j++)
                    issuedBookIds[j] = issuedBookIds[j + 1];

                issuedBookIds[bookCount - 1] = 0;
                bookCount--;
                return;
            }
        }
    }

    bool hasBook(int bookId) const
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (issuedBookIds[i] == bookId)
                return true;
        }

        return false;
    }

    int getBookCount() const
    {
        return bookCount;
    }

    void displayInfo() const override
    {
        cout << "Member ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Books Issued: " << bookCount << endl;

        if (bookCount > 0)
        {
            cout << "Book IDs: ";

            for (int i = 0; i < bookCount; i++)
            {
                cout << issuedBookIds[i] << " ";
            }

            cout << endl;
        }
    }

    friend ostream& operator<<(ostream& out, const Member& m)
    {
        out << m.id << "|" << m.name << "|" << m.phone << "|"
            << m.bookCount;

        for (int i = 0; i < m.bookCount; i++)
            out << "|" << m.issuedBookIds[i];

        return out;
    }

    friend istream& operator>>(istream& in, Member& m)
    {
        in >> m.id >> m.name >> m.phone;
        return in;
    }

    bool operator==(const Member& other) const
    {
        return id == other.id;
    }
};


class Librarian : public Person
{
private:
    int employeeId;
    double salary;

public:
    Librarian() : Person()
    {
        employeeId = 0;
        salary = 0;
    }

    Librarian(int id, string name, string phone,
              int employeeId, double salary)
        : Person(id, name, phone)
    {
        this->employeeId = employeeId;
        this->salary = salary;
    }

    void displayInfo() const override
    {
        cout << "Librarian ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Salary: " << salary << endl;
    }
};


enum class BookStatus
{
    AVAILABLE,
    ISSUED
};

enum class BookGenre
{
    FICTION,
    NONFICTION,
    TECHNOLOGY,
    SCIENCE,
    HISTORY
};


class Book
{
private:
    int bookId;
    string title;
    string author;
    string isbn;
    BookStatus status;
    BookGenre genre;
    int quantity;
    int availableCopies;

public:
    Book()
    {
        bookId = 0;
        title = "";
        author = "";
        isbn = "";
        status = BookStatus::AVAILABLE;
        genre = BookGenre::FICTION;
        quantity = 0;
        availableCopies = 0;
    }

    Book(int id, string title, string author, string isbn,
         BookGenre genre, int quantity)
    {
        bookId = id;
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        this->genre = genre;
        this->quantity = quantity;
        availableCopies = quantity;

        if (availableCopies > 0)
            status = BookStatus::AVAILABLE;
        else
            status = BookStatus::ISSUED;
    }

    int getId() const
    {
        return bookId;
    }

    string getName() const
    {
        return title;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getISBN() const
    {
        return isbn;
    }

    int getQuantity() const
    {
        return quantity;
    }

    int getAvailableCopies() const
    {
        return availableCopies;
    }

    BookStatus getStatus() const
    {
        return status;
    }

    void issueBook()
    {
        if (availableCopies <= 0)
            throw BookNotAvailableException("Book is not available.");

        availableCopies--;

        if (availableCopies == 0)
            status = BookStatus::ISSUED;
    }

    void returnBook()
    {
        if (availableCopies < quantity)
            availableCopies++;

        status = BookStatus::AVAILABLE;
    }

    void display() const
    {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Available Copies: " << availableCopies << endl;

        if (status == BookStatus::AVAILABLE)
            cout << "Status: AVAILABLE" << endl;
        else
            cout << "Status: ISSUED" << endl;
    }

    Book& operator++()
    {
        quantity++;
        availableCopies++;
        status = BookStatus::AVAILABLE;
        return *this;
    }

    Book operator++(int)
    {
        Book temp = *this;
        ++(*this);
        return temp;
    }

    Book& operator--()
    {
        if (quantity > 0)
        {
            quantity--;

            if (availableCopies > quantity)
                availableCopies = quantity;
        }

        if (availableCopies == 0)
            status = BookStatus::ISSUED;

        return *this;
    }

    Book operator--(int)
    {
        Book temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Book& other) const
    {
        return bookId == other.bookId;
    }

    bool operator<(const Book& other) const
    {
        return title < other.title;
    }

    int operator[](int index) const
    {
        if (index == 0)
            return bookId;

        if (index == 1)
            return quantity;

        if (index == 2)
            return availableCopies;

        return -1;
    }

    friend ostream& operator<<(ostream& out, const Book& b)
    {
        out << b.bookId << "|"
            << b.title << "|"
            << b.author << "|"
            << b.isbn << "|"
            << b.quantity << "|"
            << b.availableCopies;

        return out;
    }

    friend istream& operator>>(istream& in, Book& b)
    {
        in >> b.bookId >> b.title >> b.author >> b.isbn >> b.quantity;

        b.availableCopies = b.quantity;
        b.status = BookStatus::AVAILABLE;

        return in;
    }
};


template <class T>
class Container
{
private:
    T* data;
    int size;
    int capacity;

    void resize()
    {
        capacity = capacity * 2;

        T* temp = new T[capacity];

        for (int i = 0; i < size; i++)
            temp[i] = data[i];

        delete[] data;
        data = temp;
    }

public:
    Container()
    {
        size = 0;
        capacity = 5;
        data = new T[capacity];
    }

    Container(const Container& other)
    {
        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    Container& operator=(const Container& other)
    {
        if (this != &other)
        {
            delete[] data;

            size = other.size;
            capacity = other.capacity;

            data = new T[capacity];

            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }

        return *this;
    }

    ~Container()
    {
        delete[] data;
    }

    void add(const T& value)
    {
        if (size == capacity)
            resize();

        data[size] = value;
        size++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
            return;

        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];

        size--;
    }

    int find(int id) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i].getId() == id)
                return i;
        }

        return -1;
    }

    int find(string name) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i].getName() == name)
                return i;
        }

        return -1;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    void clear()
    {
        size = 0;
    }
};


class Transaction
{
private:
    static int nextId;

    int transactionId;
    int memberId;
    int bookId;
    string issueDate;
    string dueDate;
    string returnDate;
    double fineAmount;

public:
    static const double FINE_RATE;

    Transaction()
    {
        transactionId = 0;
        memberId = 0;
        bookId = 0;
        issueDate = "";
        dueDate = "";
        returnDate = "";
        fineAmount = 0;
    }

    Transaction(int memberId, int bookId,
                string issueDate, string dueDate)
    {
        transactionId = nextId++;
        this->memberId = memberId;
        this->bookId = bookId;
        this->issueDate = issueDate;
        this->dueDate = dueDate;
        returnDate = "";
        fineAmount = 0;
    }

    int getTransactionId() const
    {
        return transactionId;
    }

    int getMemberId() const
    {
        return memberId;
    }

    int getBookId() const
    {
        return bookId;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    string getReturnDate() const
    {
        return returnDate;
    }

    double getFine() const
    {
        return fineAmount;
    }

    void returnBook(string date, int overdueDays)
    {
        returnDate = date;

        if (overdueDays > 0)
            fineAmount = overdueDays * FINE_RATE;
        else
            fineAmount = 0;
    }

    void display() const
    {
        cout << "Transaction ID: " << transactionId << endl;
        cout << "Member ID: " << memberId << endl;
        cout << "Book ID: " << bookId << endl;
        cout << "Issue Date: " << issueDate << endl;
        cout << "Due Date: " << dueDate << endl;

        if (returnDate != "")
            cout << "Return Date: " << returnDate << endl;

        cout << "Fine: " << fineAmount << endl;
    }

    friend ostream& operator<<(ostream& out, const Transaction& t)
    {
        out << t.transactionId << "|"
            << t.memberId << "|"
            << t.bookId << "|"
            << t.issueDate << "|"
            << t.dueDate << "|"
            << t.returnDate << "|"
            << t.fineAmount;

        return out;
    }
};

int Transaction::nextId = 1;
const double Transaction::FINE_RATE = 5.0;


class Library
{
private:
    Container<Book> books;
    Container<Member> members;
    vector<Transaction> transactions;
    map<int, int> issuedBooks;

public:

    void addBook()
    {
        int id;
        int quantity;
        int genreChoice;

        string title;
        string author;
        string isbn;

        cout << "Enter Book ID: ";
        cin >> id;

        if (books.find(id) != -1)
            throw LibraryException("Book ID already exists.");

        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Genre (1-Fiction 2-Nonfiction 3-Technology 4-Science 5-History): ";
        cin >> genreChoice;

        BookGenre genre = BookGenre::FICTION;

        if (genreChoice == 2)
            genre = BookGenre::NONFICTION;
        else if (genreChoice == 3)
            genre = BookGenre::TECHNOLOGY;
        else if (genreChoice == 4)
            genre = BookGenre::SCIENCE;
        else if (genreChoice == 5)
            genre = BookGenre::HISTORY;

        Book b(id, title, author, isbn, genre, quantity);

        books.add(b);

        cout << "Book added successfully." << endl;
    }


    void removeBook()
    {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        int index = books.find(id);

        if (index == -1)
            throw BookNotFoundException("Book not found.");

        books.remove(index);

        cout << "Book removed successfully." << endl;
    }


    void searchBook()
    {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        int index = books.find(id);

        if (index == -1)
            throw BookNotFoundException("Book not found.");

        books[index].display();
    }


    void displayAllBooks()
    {
        if (books.getSize() == 0)
        {
            cout << "No books available." << endl;
            return;
        }

        for (int i = 0; i < books.getSize(); i++)
        {
            cout << endl;
            books[i].display();
        }
    }


    void registerMember()
    {
        int id;
        string name;
        string phone;

        cout << "Enter Member ID: ";
        cin >> id;

        if (members.find(id) != -1)
            throw LibraryException("Member ID already exists.");

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Phone: ";
        getline(cin, phone);

        Member m(id, name, phone);

        members.add(m);

        cout << "Member registered successfully." << endl;
    }


    void removeMember()
    {
        int id;

        cout << "Enter Member ID: ";
        cin >> id;

        int index = members.find(id);

        if (index == -1)
            throw MemberNotFoundException("Member not found.");

        if (members[index].getBookCount() > 0)
            throw LibraryException("Member has issued books.");

        members.remove(index);

        cout << "Member removed successfully." << endl;
    }


    void searchMember()
    {
        int id;

        cout << "Enter Member ID: ";
        cin >> id;

        int index = members.find(id);

        if (index == -1)
            throw MemberNotFoundException("Member not found.");

        members[index].displayInfo();
    }


    void displayAllMembers()
    {
        if (members.getSize() == 0)
        {
            cout << "No members available." << endl;
            return;
        }

        for (int i = 0; i < members.getSize(); i++)
        {
            cout << endl;
            members[i].displayInfo();
        }
    }


    void issueBook()
    {
        int bookId;
        int memberId;
        string issueDate;
        string dueDate;

        cout << "Enter Book ID: ";
        cin >> bookId;

        int bookIndex = books.find(bookId);

        if (bookIndex == -1)
            throw BookNotFoundException("Book not found.");

        cout << "Enter Member ID: ";
        cin >> memberId;

        int memberIndex = members.find(memberId);

        if (memberIndex == -1)
            throw MemberNotFoundException("Member not found.");

        if (members[memberIndex].getBookCount() >= 5)
            throw MaxBooksExceededException("Maximum 5 books allowed.");

        books[bookIndex].issueBook();

        members[memberIndex].addBook(bookId);

        cout << "Enter Issue Date: ";
        cin >> issueDate;

        cout << "Enter Due Date: ";
        cin >> dueDate;

        Transaction t(memberId, bookId, issueDate, dueDate);

        transactions.push_back(t);

        issuedBooks[bookId] = memberId;

        cout << "Book issued successfully." << endl;
    }


    void returnBook()
    {
        int bookId;
        int memberId;
        string returnDate;
        int overdueDays;

        cout << "Enter Book ID: ";
        cin >> bookId;

        int bookIndex = books.find(bookId);

        if (bookIndex == -1)
            throw BookNotFoundException("Book not found.");

        if (issuedBooks.find(bookId) == issuedBooks.end())
            throw LibraryException("Book is not currently issued.");

        memberId = issuedBooks[bookId];

        int memberIndex = members.find(memberId);

        if (memberIndex == -1)
            throw MemberNotFoundException("Member not found.");

        cout << "Enter Return Date: ";
        cin >> returnDate;

        cout << "Enter Overdue Days: ";
        cin >> overdueDays;

        books[bookIndex].returnBook();

        members[memberIndex].removeBook(bookId);

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getBookId() == bookId &&
                transactions[i].getMemberId() == memberId &&
                transactions[i].getReturnDate() == "")
            {
                transactions[i].returnBook(returnDate, overdueDays);
                break;
            }
        }

        issuedBooks.erase(bookId);

        cout << "Book returned successfully." << endl;
    }


    void viewOverdueBooks()
    {
        bool found = false;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getReturnDate() == "")
            {
                cout << endl;
                transactions[i].display();
                found = true;
            }
        }

        if (!found)
            cout << "No overdue books." << endl;
    }


    void saveData()
    {
        ofstream bookFile("books.txt");
        ofstream memberFile("members.txt");
        ofstream transactionFile("transactions.txt");

        if (!bookFile || !memberFile || !transactionFile)
            throw LibraryException("Unable to open file.");

        for (int i = 0; i < books.getSize(); i++)
            bookFile << books[i] << endl;

        for (int i = 0; i < members.getSize(); i++)
            memberFile << members[i] << endl;

        for (int i = 0; i < (int)transactions.size(); i++)
            transactionFile << transactions[i] << endl;

        bookFile.close();
        memberFile.close();
        transactionFile.close();

        cout << "Data saved successfully." << endl;
    }


    void loadData()
    {
        ifstream bookFile("books.txt");
        ifstream memberFile("members.txt");
        ifstream transactionFile("transactions.txt");

        if (!bookFile || !memberFile || !transactionFile)
            throw LibraryException("Data files not found.");

        cout << "Data files loaded successfully." << endl;

        bookFile.close();
        memberFile.close();
        transactionFile.close();
    }
};

}


using namespace LibrarySystem;


int main()
{
    Library library;

    int choice;

    do
    {
        cout << endl;
        cout << "===== LIBRARY MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Display All Books" << endl;
        cout << "5. Register Member" << endl;
        cout << "6. Remove Member" << endl;
        cout << "7. Search Member" << endl;
        cout << "8. Display All Members" << endl;
        cout << "9. Issue Book" << endl;
        cout << "10. Return Book" << endl;
        cout << "11. View Overdue Books" << endl;
        cout << "12. Save Data" << endl;
        cout << "13. Load Data" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                library.addBook();
                break;

            case 2:
                library.removeBook();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.displayAllBooks();
                break;

            case 5:
                library.registerMember();
                break;

            case 6:
                library.removeMember();
                break;

            case 7:
                library.searchMember();
                break;

            case 8:
                library.displayAllMembers();
                break;

            case 9:
                library.issueBook();
                break;

            case 10:
                library.returnBook();
                break;

            case 11:
                library.viewOverdueBooks();
                break;

            case 12:
                library.saveData();
                break;

            case 13:
                library.loadData();
                break;

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
            }
        }
        catch (const LibraryException& e)
        {
            cout << "Error: " << e.what() << endl;
        }
        catch (const exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    Person* p = new Member(101, "Aaditi", "9876543210");
    p->displayInfo();
    delete p;

    return 0;
}