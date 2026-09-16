#include <iostream>
#include <cstring>
using namespace std;

class LogBuffer {
    private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

    public:
    LogBuffer(int c) {
        capacity = c;
        size = 0;
        buffer = new char[capacity];
        buffer[0] = '\0';
        instanceCount++;
        cout << "Log Buffer Created. Capacity = " << capacity << endl;
    }

    LogBuffer(const LogBuffer& other) {
        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity];
        strcpy(buffer, other.buffer);
        instanceCount++;
        cout <<"Log buffer Deep Copy. capacity = " << capacity << endl;

    }

    LogBuffer& operator=(const LogBuffer& other) {
        if(this == &other) {
            cout << "Self assignemt.." << endl;
           return *this;
        }

        delete[] buffer;
        capacity = other.capacity;
        size = other.size;

        buffer = new char[capacity];
        strcpy(buffer, other.buffer);

        cout <<" LogBuffer assign..." << endl;
        return *this;

    }
    ~LogBuffer(){
    delete[] buffer;
    instanceCount--;
    cout << "Log buffer deleted.." << endl;
    }


    void append(const char* msg) {
        int msgLength = strlen(msg);
        if(size + msgLength < capacity) {
            strcat(buffer, msg);
            size = size + msgLength;
        }
        else{
            cout <<"Buffer is Full!!!" << endl;

        }

    }    

        void print() const  {
        cout << buffer << endl;
    }

    void clear() {
        size = 0;
        buffer[0] = '\0';
    }

    static int getInstanceCount() {
        return instanceCount;
    }
};

int LogBuffer::instanceCount = 0;

int main() {
    LogBuffer log1(256);
    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");
    log1.print();

    LogBuffer log2 = log1; 
    log2.append(" | Cached response sent");
    cout << "log1 : "; log1.print();
    cout << "log2 : "; log2.print();

    LogBuffer log3(128);
    log3 = log1;
    log3.print();

    log1 = log1;
    log1.print();

    cout << "Live LogBufferobjects: " << LogBuffer::getInstanceCount() << endl;
    cout << "Live LogBufferobjects: " << LogBuffer::getInstanceCount() << endl;
    return 0;

}