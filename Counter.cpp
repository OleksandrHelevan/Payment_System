#include <iostream>
#include "Counter.h"
using namespace std;

int Counter::Count=0;

void Counter::Calculate() {
    Count+=1;
}
void Counter::ShowCounter() {
    cout<<Count<<" Employees"<<endl;
}
void Counter::operator-() {
    Count--;
}
