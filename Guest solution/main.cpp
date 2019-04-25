
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: R1711791
 *
 * Created on April 14, 2019, 6:59 AM
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include<fstream>
#include<cstring>
#include <cstdlib>
#include "Guest.h"

using namespace std;
void WriteToFile(Guest guest);

void GetRecordDetails() {
    char opt;
    char ch;

    int gID;
    char gName[15];
    char gStatus[10];
    char gGender[20];
    int gAge;
    int gRoomNumber;
    int gMobileNumber;
    int gAddress;

    do {
        cout << "Enter Guest ID..";
        cin >> gID;
        cin.ignore();
        cout << "Enter Name..";
        cin.getline(gName, 15);
        cout << "Enter Status..";
        cin.getline(gStatus, 10);
        cout << "Enter your Gender";
        cin.getline(gGender, 20);
        cout << "Enter your age";
        cin>>gAge;
        cin.ignore();
        cout << "Enter your roomNumber";
        cin>>gRoomNumber;
        cin.ignore();
        cout << "Enter your MobileNumber";
        cin>>gMobileNumber;
        cin.ignore();
        cout << "Enter your Address...";
        cin>>gAddress;
        cin.ignore();


        Guest guest(gID, gName, gStatus, gGender, gAge, gRoomNumber, gMobileNumber, gAddress);
        WriteToFile(guest);

        cout << "Another record <y-yes n-no>" << endl;
        opt = getchar();
        cin.ignore();

    } while (opt != 'n');


}

void WriteToFile(Guest guest) {

    ofstream outFile("guests", ios::app | ios::binary);
    outFile.write((char*) &guest, sizeof (Guest));
    outFile.flush();

    if (outFile)
        cout << "\nRecord saved successfully" << endl;
    else
        cout << "Error saving file" << endl;

    outFile.close();

}

void ReadFromFile(streamsize position);

void ReadRecordPosition() {
    streamsize position;
    cout << "Enter the record number to retrieve...";
    cin>>position;
    ReadFromFile(position);
}

void ReadFromFile(streamsize position) {
    Guest guest;

    ifstream inFile("guests", ios::in | ios::binary);

    inFile.seekg(sizeof (Guest)*(position - 1), ios::beg);
    inFile.read((char *) &guest, sizeof (Guest));
    guest.GetGuest();
}

void Guest::makePayment(float payment, int count)
{
    installments[count] = payment; //store the payment at the selected index, passed in as an arguments
    balance += payment; //increment the balance

}

//makes use of the installments [array] to print the value at each index

void Guest::printPayments()
{
    for (int i = 0; i < 3; i++)
        {
        cout << "\tPayment " << i + 1 << " : " << installments[i] << endl;
    }
}

//calculates the outstanding bill (arreas) by subtracting the balance from the total Term Fees

float outstandingBill(Guest &guest)
{
    return guest.getBill() - guest.getBalance();
}

int main() {
    Guest guestObject; //creates the object from the class Guests
    float totalBill, installment; //create local variables to store the input from user
    cout << "\tEnter term bill      : ";
    cin >> totalBill; //get the input
    guestObject.setBill((float) totalBill); //set the Total Term Bill , note the casting of the input to a (float)

    for (int i = 0; i < 3; i++) {
        cout << "\tEnter installment " << i + 1 << "  : ";
        cin >> installment;
        guestObject.makePayment((float) installment, i); //

    }
    cout << "\n\tOutstanding fees are : " << outstandingBill(guestObject) << endl; //pass the object created on line 77 to the frined function outstandingBill
    cout << "\n\n\tTransaction History: \n\n";
    guestObject.printPayments(); //print
    cout << "\n\n"; //just to make it neat

    GetRecordDetails();
    ReadRecordPosition();
}





