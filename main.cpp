#include <string>
#include <iostream>
#include "cruise_ships.h"

template <typename T>

int main() {
    T difficulty;
    cout << "Which difficulty would you like (3,2,1)?" << endl;
    cin >> difficulty;
    while (difficulty != 1 && difficulty != 2 && difficulty != 3)
    {
        cout << "Oops! Try again" << endl;
        cin >> difficulty;
    }
    cruise * the_cruise = new cruise(difficulty);

    while (!)
    {
        /* code */
    }
    return(0);
}
