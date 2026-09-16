#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

class DataProcessor
{
public:

    virtual void loadData(const string& source) = 0;

    virtual void processData() = 0;

    virtual void exportResult(const string& destination) = 0;

    virtual string processorType() const = 0;

    virtual int recordCount() const = 0;

    virtual void printSummary() const
    {
        cout << "Processor Type: "
             << processorType() << endl;

        cout << "Records: "
             << recordCount() << endl;
    }

    virtual ~DataProcessor() = default;
};

class CSVProcessor : public DataProcessor
{
private:
    vector<string> records;

public:

    void loadData(const string& source) override
    {
        cout << "Loading CSV data from "
             << source << endl;

        records.push_back("john,25,mumbai");
        records.push_back("rahul,30,pune");
        records.push_back("aarti,22,nagpur");
        records.push_back("neha,28,nashik");
        records.push_back("rohan,35,delhi");
    }

    void processData() override
    {
        for (int i = 0; i < records.size(); i++)
        {
            for (int j = 0; j < records[i].length(); j++)
            {
                records[i][j] =
                    toupper(records[i][j]);
            }
        }
    }

    void exportResult(const string& destination) override
    {
        cout << "\n[CSV EXPORT -> "
             << destination << "]" << endl;

        for (string record : records)
        {
            cout << record << endl;
        }
    }

    string processorType() const override
    {
        return "CSV Processor";
    }

    int recordCount() const override
    {
        return records.size();
    }
};

class SensorStreamProcessor : public DataProcessor
{
private:
    vector<double> readings;

    double mean;
    double minimum;
    double maximum;

public:

    SensorStreamProcessor()
    {
        mean = 0;
        minimum = 0;
        maximum = 0;
    }

    void loadData(const string& source) override
    {
        cout << "Loading sensor data from "
             << source << endl;

        readings.push_back(23.4);
        readings.push_back(21.8);
        readings.push_back(25.1);
        readings.push_back(24.6);
        readings.push_back(22.9);
        readings.push_back(26.3);
        readings.push_back(20.7);
        readings.push_back(24.2);
    }

    void processData() override
    {
        if (readings.empty())
            return;

        double sum = 0;

        minimum = readings[0];
        maximum = readings[0];

        for (double value : readings)
        {
            sum = sum + value;

            if (value < minimum)
                minimum = value;

            if (value > maximum)
                maximum = value;
        }

        mean = sum / readings.size();
    }

    void exportResult(const string& destination) override
    {
        cout << "\n[SENSOR EXPORT -> "
             << destination << "]" << endl;

        cout << "Mean: " << mean << endl;
        cout << "Minimum: " << minimum << endl;
        cout << "Maximum: " << maximum << endl;
    }

    string processorType() const override
    {
        return "Sensor Stream Processor";
    }

    int recordCount() const override
    {
        return readings.size();
    }

    double getMean() const
    {
        return mean;
    }

    void printSummary() const override
    {
        cout << "\nProcessor Type: "
             << processorType() << endl;

        cout << "Records: "
             << recordCount() << endl;

        cout << "Mean: "
             << mean << endl;

        cout << "Minimum: "
             << minimum << endl;

        cout << "Maximum: "
             << maximum << endl;
    }
};

template <typename T>
class DataBuffer
{
private:

    T* data;

    int capacity;

    int head;

    int tail;

    int count;

public:

    DataBuffer(int capacity)
    {
        this->capacity = capacity;

        data = new T[capacity];

        head = 0;
        tail = 0;
        count = 0;
    }


    ~DataBuffer()
    {
        delete[] data;
    }


    void push(const T& value)
    {
        data[tail] = value;

        tail = (tail + 1) % capacity;

        if (count < capacity)
        {
            count++;
        }
        else
        {
            head = (head + 1) % capacity;
        }
    }


    T pop()
    {
        if (count == 0)
        {
            throw underflow_error("Buffer is empty");
        }

        T value = data[head];

        head = (head + 1) % capacity;

        count--;

        return value;
    }


    T peek() const
    {
        if (count == 0)
        {
            throw underflow_error("Buffer is empty");
        }

        return data[head];
    }


    bool isEmpty() const
    {
        return count == 0;
    }


    bool isFull() const
    {
        return count == capacity;
    }


    int size() const
    {
        return count;
    }

    template <typename U>
    friend ostream& operator<<(
        ostream& out,
        const DataBuffer<U>& buf);
};

template <typename U>
ostream& operator<<(
    ostream& out,
    const DataBuffer<U>& buf)
{
    out << "[";

    for (int i = 0; i < buf.count; i++)
    {
        int index =
            (buf.head + i) % buf.capacity;

        out << buf.data[index];

        if (i < buf.count - 1)
            out << ", ";
    }

    out << "]";

    return out;
}


int main()
{
    cout << "===== DATA PROCESSOR ====="
         << endl;

    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());

    pipeline.push_back(new SensorStreamProcessor());


    for (DataProcessor* p : pipeline)
    {
        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "------------------------"
             << endl;
    }
    cout << "\n===== DYNAMIC CAST ====="
         << endl;

    for (DataProcessor* p : pipeline)
    {
        CSVProcessor* csv =
            dynamic_cast<CSVProcessor*>(p);

        if (csv != nullptr)
        {
            cout << "Found CSV Processor with "
                 << csv->recordCount()
                 << " records." << endl;
        }

        SensorStreamProcessor* sensor =
            dynamic_cast<SensorStreamProcessor*>(p);

        if (sensor != nullptr)
        {
            cout << "Found Sensor Processor - Mean: "
                 << sensor->getMean() << endl;
        }
    }

    cout << "\n===== INTEGER BUFFER ====="
         << endl;

    DataBuffer<int> tickBuffer(5);

    for (int i = 1; i <= 7; i++)
    {
        tickBuffer.push(i * 10);
    }

    cout << "Tick Buffer: ";

    cout << "\n===== DOUBLE BUFFER ====="
         << endl;

    DataBuffer<double> tempBuffer(4);

    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);

    cout << "Before pop: "
         << tempBuffer << endl;

    cout << "Popped: "
         << tempBuffer.pop() << endl;

    cout << "After pop: "
         << tempBuffer << endl;

    cout << "\n===== STRING BUFFER ====="
         << endl;

    DataBuffer<string> logBuffer(3);

    logBuffer.push("INFO: Server started");

    logBuffer.push("WARN: High memory usage");

    logBuffer.push("ERROR: DB connection timeout");

    logBuffer.push("INFO: Retry successful");

    cout << "Log Buffer: "
         << logBuffer << endl;
    for (DataProcessor* p : pipeline)
    {
        delete p;
    }

    return 0;
}