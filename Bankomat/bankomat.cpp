#include "bankomat.h"
#include <iostream>
#include <sstream>

Bankomat::Bankomat(int atmId, int minW, int maxW) : id(atmId), minWithdraw(minW), maxWithdraw(maxW), amount100(0), amount200(0), amount500(0), amount1000(0) {}

void Bankomat::loadMoney(int num100, int num200, int num500, int num1000) {
    amount100 += num100;
    amount200 += num200;
    amount500 += num500;
    amount1000 += num1000;
    cout << "Деньги загружены в банкомат!" << endl;
}

bool Bankomat::withdrawMoney(int amount) {
    if (amount < minWithdraw) {
        cout << "Сумма меньше минимально разрешенной!" << endl;
        return false;
    }

    if (amount > maxWithdraw) {
        cout << "Сумма превышает максимально разрешенную!" << endl;
        return false;
    }

    int totalMoney = amount100 * 100 + amount200 * 200 + amount500 * 500 + amount1000 * 1000;

    if (amount > totalMoney) {
        cout << "В банкомате недостаточно денег!" << endl;
        return false;
    }

    int remainingAmount = amount;

    int num1000 = min(amount1000, remainingAmount / 1000);
    remainingAmount -= num1000 * 1000;

    int num500 = min(amount500, remainingAmount / 500);
    remainingAmount -= num500 * 500;

    int num200 = min(amount200, remainingAmount / 200);
    remainingAmount -= num200 * 200;

    int num100 = min(amount100, remainingAmount / 100);
    remainingAmount -= num100 * 100;

    if (remainingAmount == 0) {
        amount1000 -= num1000;
        amount500 -= num500;
        amount200 -= num200;
        amount100 -= num100;
        cout << "Снятие успешно!" << endl;
        return true;
    }
    else {
        cout << "Невозможно выдать указанную сумму доступными купюрами!" << endl;
        return false;
    }
}

string Bankomat::toString() {
    int totalMoney = amount100 * 100 + amount200 * 200 + amount500 * 500 + amount1000 * 1000;
    stringstream ss;
    ss << "Остаток в банкомате: " << totalMoney << " грн.";
    return ss.str();
}
