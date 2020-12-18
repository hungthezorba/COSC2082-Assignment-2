#include <iostream>
#include "Item.h"
#include <fstream>

using namespace std;

int main() {

    Item i1("I101-2001","Something","Record","2-day",1,1.45);

    i1.renting();
    i1.renting();

    cout << i1.getNumberOfCopies() << endl;
    cout << i1.renting() << endl;


    return 0;
}
