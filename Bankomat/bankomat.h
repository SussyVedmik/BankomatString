#pragma once
using namespace std;

class Bankomat {
private:
    int id; 
    int amount100; 
    int amount200; 
    int amount500; 
    int amount1000; 
    int minWithdraw;
    int maxWithdraw; 

public:
    Bankomat(int atmId, int minW, int maxW);
    void loadMoney(int num100, int num200, int num500, int num1000);
    bool withdrawMoney(int amount);
    string toString();
};


