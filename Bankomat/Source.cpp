#include "bankomat.h"
#include <iostream>

using namespace std;

int main() {
    Bankomat atm(12345, 100, 10000);
    atm.loadMoney(10, 10, 5, 2);
    atm.withdrawMoney(1500);
    cout << atm.toString() << endl;
    system("pause");
}
