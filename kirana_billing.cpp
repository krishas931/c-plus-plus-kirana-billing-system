#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Item {
private:
    string type;
    double pricePerKg;
    double pricePerGram;

public:
    Item(const string& t, double p)
        : type(t), pricePerKg(p), pricePerGram(p / 1000.0) {}

    double calculateBill(double quantity, int value) const {
        if (value == 1) {
            // quantity in kilograms
            return pricePerKg * quantity;
        } else if (value == 2) {
            // quantity in grams
            return pricePerGram * quantity;
        } else {
            // invalid choice
            return -1;
        }
    }
};

class Rice : public Item {
public:
    Rice() : Item("rice", 60.0) {}
};

class Wheat : public Item {
public:
    Wheat() : Item("wheat", 70.0) {}
};

class Sugar : public Item {
public:
    Sugar() : Item("sugar", 40.0) {}
};

class Salt : public Item {
public:
    Salt() : Item("salt", 30.0) {}
};

int main() {
    string customerName;
    string customerNumber;
    string itemType;
    double quantity;
    int value;

    Rice rice;
    Wheat wheat;
    Sugar sugar;
    Salt salt;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter customer number: ";
    getline(cin, customerNumber);

    cout << "Enter the type of item (rice, wheat, sugar, salt): ";
    getline(cin, itemType);

    cout << "Enter 1 for price per kg and 2 for price per gram: ";
    cin >> value;

    cout << "Enter the quantity of item bought: ";
    cin >> quantity;

    double totalBill = 0.0;

    if (itemType == "rice") {
        totalBill = rice.calculateBill(quantity, value);
    } else if (itemType == "wheat") {
        totalBill = wheat.calculateBill(quantity, value);
    } else if (itemType == "sugar") {
        totalBill = sugar.calculateBill(quantity, value);
    } else if (itemType == "salt") {
        totalBill = salt.calculateBill(quantity, value);
    } else {
        cout << "Invalid item type!" << endl;
        return 1;
    }

    if (totalBill == -1) {
        cout << "Invalid value entered for price choice!" << endl;
        return 1;
    }

    const double taxRate = 0.05;
    double CGST = taxRate * totalBill;
    double SGST = taxRate * totalBill;
    double totalAmount = totalBill + CGST + SGST;

    ofstream outputFile("output.txt", ios::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    outputFile << "\n\n** Kirana Store **" << endl;
    outputFile << "\n\n** Bill **" << endl;
    outputFile << "Customer Name: " << customerName << endl;
    outputFile << "Customer Number: " << customerNumber << endl;
    outputFile << "Item Type: " << itemType << endl;
    outputFile << "Quantity: " << quantity << " ";
    if (value == 1) {
        outputFile << "Kilograms" << endl;
    } else if (value == 2) {
        outputFile << "Grams" << endl;
    }

    if (itemType == "rice") {
        outputFile << "Price per unit: Rs " << rice.calculateBill(1, value)
                   << " (for rice)" << endl;
    } else if (itemType == "wheat") {
        outputFile << "Price per unit: Rs " << wheat.calculateBill(1, value)
                   << " (for wheat)" << endl;
    } else if (itemType == "sugar") {
        outputFile << "Price per unit: Rs " << sugar.calculateBill(1, value)
                   << " (for sugar)" << endl;
    } else if (itemType == "salt") {
        outputFile << "Price per unit: Rs " << salt.calculateBill(1, value)
                   << " (for salt)" << endl;
    }

    outputFile << "CGST (5%): Rs " << CGST << endl;
    outputFile << "SGST (5%): Rs " << SGST << endl;
    outputFile << "Total Amount (including tax): Rs " << totalAmount << endl;

    outputFile.close();

    cout << "\n\n** Kirana Store **" << endl;
    cout << "\n\n** Bill **" << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Customer Number: " << customerNumber << endl;
    cout << "Item Type: " << itemType << endl;
    cout << "Quantity: " << quantity << " ";
    if (value == 1) {
        cout << "Kilograms" << endl;
    } else if (value == 2) {
        cout << "Grams" << endl;
    }

    if (itemType == "rice") {
        cout << "Price per unit: Rs " << rice.calculateBill(1, value)
             << " (for rice)" << endl;
    } else if (itemType == "wheat") {
        cout << "Price per unit: Rs " << wheat.calculateBill(1, value)
             << " (for wheat)" << endl;
    } else if (itemType == "sugar") {
        cout << "Price per unit: Rs " << sugar.calculateBill(1, value)
             << " (for sugar)" << endl;
    } else if (itemType == "salt") {
        cout << "Price per unit: Rs " << salt.calculateBill(1, value)
             << " (for salt)" << endl;
    }

    cout << "CGST (5%): Rs " << CGST << endl;
    cout << "SGST (5%): Rs " << SGST << endl;
    cout << "Total Amount (including tax): Rs " << totalAmount << endl;

    return 0;
}
