#include<iostream>
#include<fstream>
#include <string>
#include "CustomerData.h"

int CustomerData(){
    Customer listCus[100];
    string s;
    int temp3 = 0;
    ifstream myfile("customers.txt");
    if (myfile)
    {
        int temp2 = 0;
        while (getline(myfile, s))  // same as: while (getline( myfile, line ).good())
        {
            if (s[0] == 'C') {
                temp3 = 0;
                string listtemp[10];
                string delimiter = ",";
                size_t pos = 0;
                string token;
                int temp = 0;
                while ((pos = s.find(delimiter)) != string::npos) {
                    token = s.substr(0, pos);
                    listtemp[temp] = token;
                    s.erase(0, pos + delimiter.length());
                    temp++;
                }
                listtemp[temp] = s;
                listCus[temp2].ID = listtemp[0];
                listCus[temp2].name = listtemp[1];
                listCus[temp2].address = listtemp[2];
                listCus[temp2].phone = listtemp[3];
                listCus[temp2].numOfRentals = listtemp[4];
                listCus[temp2].typeCus = listtemp[5];
                temp2++;
            }
            else {
                listCus[temp2-1].listOfRentals[temp3] = s;
                temp3++;
            }

        }
        myfile.close();
    }

    int input;
    cout << "Enter customer number: ";
    cin >> input;

    int cusNum = input;
    string customerInfoList[100];
    int arraySize = stoi(listCus[cusNum].numOfRentals);
    string customerRentItem[arraySize];
        customerInfoList[0] = listCus[cusNum].ID;
        customerInfoList[1] = listCus[cusNum].name;
        customerInfoList[2] = listCus[cusNum].address;
        customerInfoList[3] = listCus[cusNum].phone;
        customerInfoList[4] = listCus[cusNum].numOfRentals;
        customerInfoList[5] = listCus[cusNum].typeCus;


        for (int j = 0; j < arraySize; j++){
            customerRentItem[j] = listCus[cusNum].listOfRentals[j];
        }

    cout << customerInfoList[0] << endl;
    cout << customerInfoList[1] << endl;
    cout << customerInfoList[2] << endl;
    cout << customerInfoList[3] << endl;
    cout << customerInfoList[4] << endl;
    cout << customerInfoList[5] << endl;

    for (int j = 0; j < arraySize; j++) {
        cout << customerRentItem[j] <<endl;
    }


}













