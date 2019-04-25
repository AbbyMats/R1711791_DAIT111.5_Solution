#include <iostream>
#include<fstream>
#include<cstring>
#include <cstdlib>
#include "Guest.h"

using namespace std;

Guest::Guest()
{

}
Guest::Guest(int gID, char* gn, char* gs, char* ggen, int gag, int grn, int gmn, int gad) {
        guestID = gID;
        strcpy(name, gn);
        strcpy(status, gs);
        strcpy(gender, ggen);
        age = gag;
        roomNumber = grn;
        mobileNumber = gmn;
        address = gad;

    }
void Guest::GetGuest() {
        cout << "\n";
        cout << "Guest ID...." << guestID << endl;
        cout << "Name...." << name << endl;
        cout << "Status...." << status << endl;
        cout << "Gender..." << gender << endl;
        cout << "Age..." << age << endl;
        cout << "RoomNumber..." << roomNumber << endl;
        cout << "MobileNumber..." << mobileNumber << endl;
        cout << "Address..." << address << endl;
    }


