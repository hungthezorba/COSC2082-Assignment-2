#include<iostream>
#include<fstream>
#include <string>
#include "ItemData.h"

using namespace std;

int ItemData() {
    Items listItem[100];
    string sitem;
    int temp3item = 0;
    ifstream itemfile("items.txt");
    if (itemfile)
    {
        int temp2 = 0;
        while (getline(itemfile, sitem))  // same as: while (getline( myfile, line ).good())
        {
            if (sitem[0] == 'I') {
                temp3item = 0;
                string listtemp[10];
                string delimiter = ",";
                size_t pos = 0;
                string token;
                int temp = 0;
                while ((pos = sitem.find(delimiter)) != string::npos) {
                    token = sitem.substr(0, pos);
                    listtemp[temp] = token;
                    sitem.erase(0, pos + delimiter.length());
                    temp++;
                }
                listtemp[temp] = sitem;
                listItem[temp2].id = listtemp[0];
                listItem[temp2].title = listtemp[1];
                listItem[temp2].rentalType = listtemp[2];
                listItem[temp2].loanType = listtemp[3];
                listItem[temp2].numOfStock = listtemp[4];
                listItem[temp2].rentalFee = listtemp[5];
                listItem[temp2].genres = listtemp[6];
                if(listItem[temp2].genres == ""){
                    listItem[temp2].genres = "NAN";
                }
                temp2++;
            }


        }
        itemfile.close();
    }
    int input;
    cout << "Enter item number: ";
    cin >> input;
    int itemNum = input;
    string itemList[100];

    itemList[0] = listItem[itemNum].id;
    itemList[1] = listItem[itemNum].title;
    itemList[2] = listItem[itemNum].rentalFee;
    itemList[3] = listItem[itemNum].loanType;
    itemList[4] = listItem[itemNum].numOfStock;
    itemList[5] = listItem[itemNum].rentalFee;
    itemList[6] = listItem[itemNum].genres;

    for (int i = 0; i < 7 ; i++) {
        cout << itemList[i] << endl;
    }


}
