#include <iostream>
using namespace std;

class Inventory {
    private:
    int productID;
    string name;
    double price;
    int quantity;

    public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productID;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << productID << " " << name << " " << price << " " << quantity << " " << totalValue() << endl;
    
    }
    double totalValue() const {
        return price * quantity;
    }
    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

};    
    double reorderCost(int qty, double unitPrice) {
        return qty * unitPrice;
    }
    double reorderCost(double qty, double unitPrice) {
        return qty * unitPrice;
    }
    double reorderCost(int qty, double unitPrice, double taxRate) {
        double cost = qty * unitPrice;
        return cost + (cost * taxRate / 100);
    }
    double applyDiscount(double price, double discountPercent = 10.0) {
        return price - (price * discountPercent / 100);
    }



int main() {
    Inventory product[5];

    for(int i = 0; i < 5; i++) {
        cout <<"\nEnter Products: " << i + 1 << endl;
        product[i].acceptDetails();
    }

    cout << "\n---------Products----------" << endl;
    for(int i = 0; i < 5; i++) {
        product[i].displayDetails();
    }
    int highest = 0;
    for(int i = 0; i < 5; i++) {
        if(product[i].totalValue() > product[highest].totalValue()) {
            highest = if;
        }    
        
    }
    cout << "\nHighest Value Product: " << endl;
    product[highest].displayDetails();

    int threshold;
    cout << "\nEnter Low Stock Threshold: ";
    cin >> threshold;

    cout << "-------Low Stock Products------" << endl;
    for(int i = 0; i < 5; i++) {
        if(product[i].isLowStock(threshold)) {
            product[i].displayDetails();
        }
    }
    cout << "\n----Reorder List ------" << endl;
    cout << "Integer quantity cost: " << reorderCost(10, 50.0) << endl;
    cout << "Code with Tax: " << reorderCost(10, 50.0, 18.0) << endl;

    cout << "\n---------Discount--------" << endl;
    cout << "10% Discount: " << applyDiscount(1000) << endl;
    cout << "20% Discount: " << applyDiscount(1000, 20) << endl;

   
   return 0;
}