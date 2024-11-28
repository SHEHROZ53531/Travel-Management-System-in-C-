#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


void menu();

class ManageMenu {
protected:
    string userName;

public:
    ManageMenu() {
        system("color 0A");
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu();
    }
};

class Customer {
public:
    string name, gender, address;
    int age, mobileNo, menuBack;
    static int cusID;
    char all[999];

    void getDetails() {
        ofstream out("old-customers.txt", ios::app);

        if (out.is_open()) {
            cout << "\n========================================" << endl;
            cout << "           Add New Customer             " << endl;
            cout << "========================================" << endl;

            cout << "Enter Customer ID       : ";
            cin >> cusID;
            cout << "Enter Full Name         : ";
            cin >> name;
            cout << "Enter Age               : ";
            cin >> age;
            cout << "Enter Mobile Number     : ";
            cin >> mobileNo;
            cout << "Enter Address           : ";
            cin >> address;
            cout << "Enter Gender (M/F/Other): ";
            cin >> gender;

            // Writing to file
            out << "========================================" << endl;
            out << "Customer Details:" << endl;
            out << "----------------------------------------" << endl;
            out << "Customer ID   : " << cusID << endl;
            out << "Name          : " << name << endl;
            out << "Age           : " << age << endl;
            out << "Mobile Number : " << mobileNo << endl;
            out << "Address       : " << address << endl;
            out << "Gender        : " << gender << endl;
            out << "========================================" << endl;
            out << endl;

            out.close();
            cout << "\nDetails Saved Successfully!" << endl;
            cout << "NOTE: Your information is securely stored for future purposes.\n" << endl;
        }
        else {
            cout << "Error: Unable to open the file for saving details!" << endl;
        }
        // Ask user if they want to go back to the main menu or exit
        int choice;
        cout << "Press 1 to return to the main menu or 2 to exit the program: ";
        cin >> choice;
        system("CLS");
        if (choice == 1) {
            menu();
        }
        else {
            cout << "Thank you for using the Travel Management System!" << endl;
            exit(0);
        }
    }

    void showDetails() {
        ifstream in("old-customers.txt");
        {
            if (!in) {
                cout << "File Error!" << endl;
                return;
            }
            while (!(in.eof())) {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
        // Ask user if they want to go back to the main menu or exit
        int choice;
        cout << "\nPress 1 to return to the main menu or 2 to exit the program: ";
        cin >> choice;
        system("CLS");
        if (choice == 1) {
            menu();
        }
        else {
            cout << "Thank you for using the Travel Management System!" << endl;
            exit(0);
        }
    }
};

int Customer::cusID;

class Cabs {
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;

    void cabDetails() {
        int cabChoice, kilometers;
        double cabCost;

        cout << "\n=============================================================" << endl;
        cout << "       Welcome to ABC Cabs - Your Trusted Travel Partner      " << endl;
        cout << "=============================================================" << endl;
        cout << "We collaborate with the fastest, safest, and smartest cab services nationwide." << endl;
        cout << "\nAvailable Cab Options:" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "  1. Standard Cab - Rs. 15 per KM" << endl;
        cout << "  2. Luxury Cab   - Rs. 25 per KM" << endl;
        cout << "  3. Mini Cab     - Rs. 10 per KM" << endl;
        cout << "  4. SUV Cab      - Rs. 30 per KM" << endl;
        cout << "-------------------------------------------------------------" << endl;

        cout << "\nTo calculate the cost of your journey, please provide the following details:" << endl;


        cout << "Enter the type of cab you need (1-4): ";
        cin >> cabChoice;

        cout << "Enter the number of kilometers you need to travel: ";
        cin >> kilometers;

        // Calculate cab cost based on choice
        cout << fixed << setprecision(2); // Format for monetary values
        switch (cabChoice) {
        case 1:
            cabCost = kilometers * 15;
            cout << "\nYou selected a *Standard Cab*. Your total cost is Rs. " << cabCost << "." << endl;
            lastCabCost = cabCost;
            break;
        case 2:
            cabCost = kilometers * 25;
            cout << "\nYou selected a *Luxury Cab*. Your total cost is Rs. " << cabCost << "." << endl;
            lastCabCost = cabCost;
            break;
        case 3:
            cabCost = kilometers * 10;
            cout << "\nYou selected a *Mini Cab*. Your total cost is Rs. " << cabCost << "." << endl;
            lastCabCost = cabCost;
            break;
        case 4:
            cabCost = kilometers * 30;
            cout << "\nYou selected an *SUV Cab*. Your total cost is Rs. " << cabCost << "." << endl;
            lastCabCost = cabCost;
            break;
        default:
            cout << "\nInvalid Input! Redirecting to the previous menu. Please wait..." << endl;
            Sleep(1100); // Pause for 1.1 seconds
            system("CLS"); // Clear the screen (Windows-specific)
            menu();
        }

        cout << "\n-------------------------------------------------------------" << endl;
        cout << "       Thank you for booking with ABC Cabs!                  " << endl;
        cout << "       Your cab has been booked successfully.                " << endl;
        cout << "-------------------------------------------------------------" << endl;


        // Ask user if they want to go back to the main menu or exit
        int choice;
        cout << "Press 1 to return to the main menu or 2 to exit the program: ";
        cin >> choice;
        system("CLS");
        if (choice == 1) {
            menu();
        }
        else {
            cout << "Thank you for using the Travel Management System!" << endl;
            exit(0);
        }
    }
};

float Cabs::lastCabCost = 0;
class ExploreTours {
    string selectedPackage;
    float packageCost;

public:
    void showPackages() {
        cout << "\n====================================================" << endl;
        cout << "       Explore Our Exciting Tour Packages!          " << endl;
        cout << "====================================================" << endl;
        cout << "1. Wildlife Safari - Rs. 25,000" << endl;
        cout << "2. Mountain Adventure - Rs. 20,000" << endl;
        cout << "3. Beach Getaway - Rs. 15,000" << endl;
        cout << "4. City Tour - Rs. 10,000" << endl;

        cout << "\nSelect a package to book: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            selectedPackage = "Wildlife Safari";
            packageCost = 25000;
            break;
        case 2:
            selectedPackage = "Mountain Adventure";
            packageCost = 20000;
            break;
        case 3:
            selectedPackage = "Beach Getaway";
            packageCost = 15000;
            break;
        case 4:
            selectedPackage = "City Tour";
            packageCost = 10000;
            break;
        default:
            cout << "Invalid choice! Returning to the menu..." << endl;
            return;
        }

        cout << "\nYou selected: " << selectedPackage << " - Rs. " << packageCost << endl;

        int userChoice;
        cout << "\nPress 1 to return to the main menu or 2 to exit the program: ";
        cin >> userChoice;
        system("CLS");
        if (userChoice == 1) {
            menu();
        }
        else {
            cout << "Thank you for using the Travel Management System!" << endl;
            exit(0);
        }
    }
    string getSelectedPackage() {
        return selectedPackage;
    }

    float getPackageCost() {
        return packageCost;
    }
};

class TravelInsurance {
    string selectedPlan;
    float planCost;

public:
    void showInsurancePlans() {
        cout << "\n====================================================" << endl;
        cout << "         Affordable Travel Insurance Plans          " << endl;
        cout << "====================================================" << endl;
        cout << "1. Basic Plan   - Rs. 500" << endl;
        cout << "2. Premium Plan - Rs. 1,000" << endl;
        cout << "3. VIP Plan     - Rs. 2,500" << endl;

        cout << "\nSelect a plan to purchase: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            selectedPlan = "Basic Plan";
            planCost = 500;
            break;
        case 2:
            selectedPlan = "Premium Plan";
            planCost = 1000;
            break;
        case 3:
            selectedPlan = "VIP Plan";
            planCost = 2500;
            break;
        default:
            cout << "Invalid choice! No plan selected." << endl;
            return;
        }

        cout << "\nYou selected: " << selectedPlan << " - Rs. " << planCost << endl;
        int userChoice;
        cout << "\nPress 1 to return to the main menu or 2 to exit the program: ";
        cin >> userChoice;
        system("CLS");
        if (userChoice == 1) {
            menu();
        }
        else {
            cout << "Thank you for using the Travel Management System!" << endl;
            exit(0);
        }

    }
    string getSelectedPlan() {
        return selectedPlan;
    }


    float getPlanCost() {
        return planCost;
    }
};
class Booking {
public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;

    void hotels() {
        cout << "\n====================================================" << endl;
        cout << "         Affordable Hotels Packages          " << endl;
        cout << "====================================================" << endl;
        cout << "1. Avendra (Rs. 5000 per night)" << endl;
        cout << "2. ChoiceYou (Rs. 3000 per night)" << endl;
        cout << "3. ElephantBay (Rs. 4000 per night)" << endl;
        cout << "4. OceanView (Rs. 4500 per night)" << endl;
        cout << "5. HillTop (Rs. 3500 per night)" << endl;

        cout << "\nEnter the hotel you want to book: ";
        cin >> choiceHotel;

        switch (choiceHotel) {
        case 1:
            cout << "You have chosen Hotel Avendra\n" << endl;
            cout << "Packages:\n1. Standard Pack (Rs. 5000)\n2. Premium Pack (Rs. 8000)\n";
            cout << "Select a package: ";
            cin >> packChoice;
            hotelCost = (packChoice == 1) ? 5000 : 8000;
            break;
        case 2:
            cout << "You have chosen Hotel ChoiceYou\n" << endl;
            cout << "Packages:\n1. Standard Pack (Rs. 3000)\n2. Premium Pack (Rs. 6000)\n";
            cout << "Select a package: ";
            cin >> packChoice;
            hotelCost = (packChoice == 1) ? 3000 : 6000;
            break;
        case 3:
            cout << "You have chosen Hotel ElephantBay\n" << endl;
            cout << "Packages:\n1. Standard Pack (Rs. 4000)\n2. Premium Pack (Rs. 7000)\n";
            cout << "Select a package: ";
            cin >> packChoice;
            hotelCost = (packChoice == 1) ? 4000 : 7000;
            break;
        case 4:
            cout << "You have chosen Hotel OceanView\n" << endl;
            cout << "Packages:\n1. Standard Pack (Rs. 4500)\n2. Premium Pack (Rs. 7500)\n";
            cout << "Select a package: ";
            cin >> packChoice;
            hotelCost = (packChoice == 1) ? 4500 : 7500;
            break;
        case 5:
            cout << "You have chosen Hotel HillTop\n" << endl;
            cout << "Packages:\n1. Standard Pack (Rs. 3500)\n2. Premium Pack (Rs. 6500)\n";
            cout << "Select a package: ";
            cin >> packChoice;
            hotelCost = (packChoice == 1) ? 3500 : 6500;
            break;
        default:
            cout << "Invalid Choice! Redirecting to Menu...\n";
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Hotel Booked Successfully!\n";

        // Ask user if they want to go back to the main menu or exit
        int choice;
        cout << "Press 1 to return to the main menu or 2 to exit the program: ";
        cin >> choice;
        system("CLS");
        if (choice == 1) {
            menu();
        }
        else {
            cout << "Thank you for using the Travel Management System!" << endl;
            exit(0);
        }
    }
};

float Booking::hotelCost = 0;

class Receipt {
public:
    void generateReceipt(string tourPackage, float packageCost, string insurancePlan, float insuranceCost) {
        cout << "\n\t---Receipt---" << endl;
        cout << "Customer ID: " << Customer::cusID << endl;
        cout << "Total Cab Cost: Rs. " << Cabs::lastCabCost << endl;
        cout << "Total Hotel Cost: Rs. " << Booking::hotelCost << endl;

        if (!tourPackage.empty()) {
            cout << "Selected Tour Package: " << tourPackage << " - Rs. " << packageCost << endl;
        }
        if (!insurancePlan.empty()) {
            cout << "Selected Insurance Plan: " << insurancePlan << " - Rs. " << insuranceCost << endl;
        }

        float totalBill = Cabs::lastCabCost + Booking::hotelCost + packageCost + insuranceCost;

        cout << "Total Bill: Rs. " << totalBill << endl;

        ofstream receiptFile("receipt.txt", ios::app);
        if (receiptFile.is_open()) {
            receiptFile << "=================================" << endl;
            receiptFile << "         ABC Travel Agency       " << endl;
            receiptFile << "            Official Receipt     " << endl;
            receiptFile << "=================================" << endl;
            receiptFile << "Customer ID       : " << Customer::cusID << endl;
            receiptFile << "---------------------------------" << endl;
            receiptFile << "Service Details:" << endl;
            receiptFile << "  - Total Cab Cost : Rs. " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            receiptFile << "  - Total Hotel Cost : Rs. " << fixed << setprecision(2) << Booking::hotelCost << endl;
            if (!tourPackage.empty()) receiptFile << "  - Tour Package : " << tourPackage << " - Rs. " << packageCost << endl;
            if (!insurancePlan.empty()) receiptFile << "  - Insurance Plan : " << insurancePlan << " - Rs. " << insuranceCost << endl;
            receiptFile << "---------------------------------" << endl;
            receiptFile << "Total Amount Due  : Rs. " << fixed << setprecision(2) << totalBill << endl;
            receiptFile << "=================================" << endl;
            receiptFile << "     Thank you for choosing us!  " << endl;
            receiptFile << " We hope to serve you again soon." << endl;
            receiptFile << "=================================" << endl;
            receiptFile << endl;
            receiptFile.close();
        }
        else {
            cout << "Error: Unable to save the receipt!" << endl;
        }
    }

};



void menu() {
    int mainChoice;
    static Customer customer;        
    static Cabs cab;              
    static Booking booking;
    Receipt receipt;
    static ExploreTours tours;     
    static TravelInsurance insurance;

    cout << "\n\t\t\t* Welcome to ABC Travels *\n" << endl;
    cout << "=============================================================" << endl;
    cout << "                         MAIN MENU                          " << endl;
    cout << "=============================================================" << endl;

    cout << "-------------------------------------------------------------" << endl;
    cout << "|                                                           |" << endl;
    cout << "|   1. Add New Customer                                     |" << endl;
    cout << "|   2. View Customer Details                                |" << endl;
    cout << "|   3. Book a Cab                                           |" << endl;
    cout << "|   4. Book a Hotel                                         |" << endl;
    cout << "|   5. Tour Packages                                        |" << endl;
    cout << "|   6. Insurance Plans                                      |" << endl;
    cout << "|   7. Generate Receipt                                     |" << endl;
    cout << "|   8. Exit                                                 |" << endl;
    cout << "|                                                           |" << endl;
    cout << "-------------------------------------------------------------" << endl;

    cout << "\nPlease enter your choice (1-8): ";
    cin >> mainChoice;


    switch (mainChoice) {
    case 1:
        customer.getDetails();
        break;
    case 2:
        customer.showDetails();
        break;
    case 3:
        cab.cabDetails();
        break;
    case 4:
        booking.hotels();
        break;
    case 5:
        tours.showPackages();
        break;
    case 6:
        insurance.showInsurancePlans();
        break;
    case 7:
        receipt.generateReceipt(
            tours.getSelectedPackage(),
            tours.getPackageCost(),
            insurance.getSelectedPlan(),
            insurance.getPlanCost()
        );
        break;

    case 8:
        cout << "Thank you for using the Travel Management System!" << endl;
        exit(0);
    default:
        cout << "Invalid Input! Redirecting to Main Menu...\n";
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main() {
    ManageMenu start;
    return 0;
}
