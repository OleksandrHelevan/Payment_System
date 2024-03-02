
#ifndef PAYMENT_SYSTEM_COUNTER_H
#define PAYMENT_SYSTEM_COUNTER_H
#include <iostream>

using namespace std;

class Counter {
    static int Count;
public:
    void Calculate();
    void ShowCounter();
    void operator-();
};


#endif //PAYMENT_SYSTEM_COUNTER_H
