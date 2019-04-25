#include <iostream>
#include<fstream>
#include<cstring>
#include <cstdlib>
#ifndef GUEST_H
#define GUEST_H


class Guest
{
    int guestID;
    char name[15];
    char status[10];
    int installments[3];
    float termBill;
    float balance;
    char gender[20];
    int age;
    int roomNumber;
    int mobileNumber;
    int address;

public:

         void setBill(float thisBill) {
        termBill = thisBill;
    }

    float getBill() {
        return termBill;
    }

        Guest();
        Guest(int gID, char* n, char* s, char* gen, int ag, int rn, int mn, int ad);
        void GetGuest();
 void makePayment(float payment, int count); // the meat of the program, takes a payment and an index named count, implemented
    // below the Class Declaration, line 56
    void printPayments(); // Just prints out all the payments made

    float getBalance() { // returns the amount owed by the Student
        return balance;
    }
    friend float outstandingBill();
};

#endif /* GUEST_H*/
