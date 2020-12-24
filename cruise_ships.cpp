#include <string>
#include <iostream>
#include "cruise_ships.h"

using namespace std;

route::route(const int diff_in) : difficulty(diff_in) {}
void route::short_way() {
    
}
void route::long_way() {

}

cruise::cruise(const int turns_in,const string start_in,const string dest_in,const int diff_in) : 
    turns(turns_in),start(start_in),destination(dest_in),difficulty(diff_in) {}

int cruise::get_turns() {
    return turns;
}
void cruise::count_down_turns() {
    turns--;
}
void cruise::progress(const int route_choice) {
    if (route_choice == 1)
    {
        this.path(difficulty);
    }
    
}
void cruise::disease() {
    
}
void cruise::breakdown() {
    
}
void cruise::win() {
    
}

class diseased_pirates : public pirate {

};

class killer_pirates : public pirate {

};

class wrecking_priates : public pirate {

};

