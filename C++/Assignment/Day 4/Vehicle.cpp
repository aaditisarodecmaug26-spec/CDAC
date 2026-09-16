#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(string reg, string owner, int year, double km)
    {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;

        cout << "[Vehicle Constructor] " << registrationNo
             << " : " << ownerName << endl;
    }

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual string vehicleType() const = 0;

    virtual void describe() const
    {
        cout << "Registration: " << registrationNo << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Year: " << yearOfManufacture << endl;
        cout << "KM Driven: " << kmDriven << endl;
    }

    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] " << registrationNo << endl;
    }

    double getKmDriven() const
    {
        return kmDriven;
    }

    string getRegNo() const
    {
        return registrationNo;
    }

    string getOwnerName() const
    {
        return ownerName;
    }
};

class Car : public Vehicle
{
private:
    string fuelType;
    double mileageKmpl;

public:
    Car(string reg, string owner, int year, double km,
        string fuel, double mileage)
        : Vehicle(reg, owner, year, km)
    {
        fuelType = fuel;
        mileageKmpl = mileage;

        cout << "[Car Constructor] " << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double price;

        if (fuelType == "Petrol")
            price = 106.00;
        else
            price = 93.00;

        return (kmToTravel / mileageKmpl) * price;
    }

    string vehicleType() const override
    {
        return "Car";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileageKmpl << " km/l" << endl;
    }

    ~Car()
    {
        cout << "[Car Destructor] " << registrationNo << endl;
    }
};

class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(string reg, string owner, int year, double km,
          double payload, double efficiency)
        : Vehicle(reg, owner, year, km)
    {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;

        cout << "[Truck Constructor] " << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double efficiency = fuelEfficiencyKmpl;

        efficiency = efficiency * (1 - 0.05 * payloadCapacityTons);

        double fuelUsed = kmToTravel / efficiency;

        return fuelUsed * 93.00;
    }

    string vehicleType() const override
    {
        return "Truck";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload: " << payloadCapacityTons << " tons" << endl;
        cout << "Fuel Efficiency: " << fuelEfficiencyKmpl << " km/l" << endl;
    }

    ~Truck()
    {
        cout << "[Truck Destructor] " << registrationNo << endl;
    }
};

class ElectricTruck : public Truck
{
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:
    ElectricTruck(string reg, string owner, int year, double km,
                  double payload, double efficiency,
                  double battery, double range)
        : Truck(reg, owner, year, km, payload, efficiency)
    {
        batteryCapacityKWh = battery;
        rangePerChargeKm = range;

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / rangePerChargeKm)
               * batteryCapacityKWh * 9.50;
    }

    string vehicleType() const override
    {
        return "Electric Truck";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Battery: " << batteryCapacityKWh << " kWh" << endl;
        cout << "Range: " << rangePerChargeKm << " km" << endl;
    }

    ~ElectricTruck()
    {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};
class Van : public Vehicle
{
private:
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(string reg, string owner, int year, double km,
        int seats, double mileage)
        : Vehicle(reg, owner, year, km)
    {
        seatingCapacity = seats;
        mileageKmpl = mileage;

        cout << "[Van Constructor] " << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / mileageKmpl) * 106.00;
    }

    string vehicleType() const override
    {
        return "Van";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Seats: " << seatingCapacity << endl;
        cout << "Mileage: " << mileageKmpl << " km/l" << endl;
    }

    ~Van()
    {
        cout << "[Van Destructor] " << registrationNo << endl;
    }
};

void printFleetReport(const vector<Vehicle*>& fleet, double tripKm)
{
    cout << "\n===== FLEET REPORT =====" << endl;

    cout << "Registration\tType\t\tOwner\t\tKM Driven" << endl;

    double lowestCost = 999999999;
    Vehicle* efficientVehicle = nullptr;

    for (Vehicle* v : fleet)
    {
        double cost = v->fuelCost(tripKm);

        cout << v->getRegNo() << "\t\t"
             << v->vehicleType() << "\t"
             << v->getOwnerName() << "\t"
             << v->getKmDriven() << endl;

        if (cost < lowestCost)
        {
            lowestCost = cost;
            efficientVehicle = v;
        }
    }

    cout << "\n===== FUEL / CHARGE COST =====" << endl;

    for (Vehicle* v : fleet)
    {
        cout << v->getRegNo()
             << " (" << v->vehicleType() << ") : Rs. "
             << v->fuelCost(tripKm) << endl;
        ElectricTruck* electric =
            dynamic_cast<ElectricTruck*>(v);

        if (electric != nullptr)
        {
            cout << "Battery information available for Electric Truck"
                 << endl;
        }
    }

    cout << "\nMost Efficient Vehicle: "
         << efficientVehicle->getRegNo()
         << " (" << efficientVehicle->vehicleType() << ")"
         << " - Rs. " << lowestCost << endl;
}


int main()
{
    cout << "===== CONSTRUCTOR ORDER =====" << endl;

    {
        ElectricTruck et(
            "V-ET001","Green Logistics", 2024, 50000, 5, 4, 100, 300);

        cout << "\nElectric Truck created.\n";
    }

    cout << "\n===== POLYMORPHIC FLEET =====" << endl;

    vector<Vehicle*> fleet;

    fleet.push_back(new Car("KA01AA001", "Ramesh Kumar", 2020, 45200, "Petrol", 15));

    fleet.push_back(new Truck("MH04BB002", "Shyam Logistics", 2019, 123500, 4, 6));

    fleet.push_back(new ElectricTruck("GJ07CC003", "Green Fleet Co", 2023, 89000, 2, 5, 85, 250));

    fleet.push_back(new Van("MH12DD004", "City Travels", 2021, 67000, 8, 12));

    fleet.push_back(new Car("DL05EE005", "Amit Sharma", 2022, 30000, "Diesel", 18));

    printFleetReport(fleet, 200);

    // Cleanup
    cout << "\n===== CLEANUP =====" << endl;

    for (Vehicle* v : fleet)
    {
        delete v;
    }

    return 0;
}