# Kirana Store Billing System – C++

## 📌 Overview
This project is a simple billing application developed using C++. It helps a Kirana (general) store shopkeeper generate customer bills based on items purchased and quantity selected. The system supports billing in both kilograms and grams and includes GST calculation with CGST and SGST.

## 🎯 Objective
To automate the basic billing process in a grocery shop using C++ OOP principles and file handling. 

## 🛠️ Tech Used
- Language: C++
- Concepts: OOP, Inheritance, Classes, File Handling (Bill stored in `output.txt`)

## ✨ Features
- User input for customer name, number, and item selection
- Quantity selection in **kg or grams**
- Predefined prices for:
  - Rice: ₹60/kg
  - Wheat: ₹70/kg
  - Sugar: ₹40/kg
  - Salt: ₹30/kg
- Calculates total cost based on weight
- Adds **CGST + SGST (5% each)**
- Shows output on **CMD & in a file (output.txt)**

## 🧩 Classes Used
| Class | Purpose |
|------|---------|
| `Item` | Base class storing item type & price values |
| `Rice`, `Wheat`, `Sugar`, `Salt` | Derived classes with predefined prices |

## ▶️ How to Run the Program
1. Compile the file:
   ```bash
   g++ kirana_billing.cpp -o kirana_billing

