#include <string>
#include <iostream>
#include "cruise_ships.h"

using namespace std;

route::route(const int halfway_in) : halfway(halfway_in) {} 

void route::way(cruise &player_cruise,bool long_way) {
    int result = rand() % 100;
    if (long_way)
    {
        player_cruise.count_down_turns(10);
        result = result / 3;
    }
    player_cruise.count_down_turns(10);
    
    if (player_cruise.get_turns() < halfway)
    {
        result = result / 4;        
    }
    if (result < ENCOUNTER_DISEASES)
    {
        player_cruise.disease();
    }
    if (result < ENCOUNTER_MECH_FAILURE)
    {
        player_cruise.breakdown();
    }
    if (result < ENCOUNTER_STORM)
    {
        player_cruise.storm();
    }
    if (result < ENCOUNTER_PIRATES)
    {
        pirate * foo =  pirate_maker(player_cruise.get_turns());
        foo->harm(player_cruise);
    }
}

cruise::cruise(const int diff_in) : 
    difficulty(diff_in) {
        int rand1,rand2,rand3 = rand() % 10;
        start.name = names[rand1] + other_names[rand2] + identifiers[rand3];
        start.finish_distance = 10;
        destination.name = names[rand3] + other_names[rand2] + identifiers[rand1];
        destination.finish_distance = 0;
        boat = new ship;
        if (diff_in == 3)
        {
            boat->turns == 70;
        }
        else if (diff_in == 2)
        {
            boat->turns == 80;
        }
        else 
        {
            boat->turns == 100;
        }
        path = new route(boat->turns / 2);
    }

int cruise::get_turns() {
    return boat->turns;
}
void cruise::count_down_turns(const int decrement) {
    boat->turns -= decrement;
}
void cruise::count_down_lives(const int decrement) {
    boat->tourists -= decrement;
}
void cruise::progress(const int route_choice) {
    if (route_choice == 1)
    {
        path->way(*this,true);
    }
    else if (route_choice == 2)
    {
        path->way(*this,false);   
    }
    else
    {
        cout << "wrong choice" << endl;
    }
    
}
void cruise::breakdown() {
    boat->turns = boat->turns / 1.2;
}
void cruise::storm() {
    int result = rand() * 10;
    if (result % 4 == 0)
    {
        count_down_lives(-10);
        cout << "You fell into the bermuda triangle and ended up closer to your destination!" << endl;
    }
    if (result % 3 == 0)
    {
        breakdown();
    }
}
bool cruise::win() {
    if ((boat->turns != 0) && (start.finish_distance == 0))
    {
        return(true);
    }
    return(false);
}

class killer_pirate : public pirate {
    public:
    int harm(cruise &boat) {
        boat.count_down_lives(10);
    }
    string get_type() {
        return "Killers";
    }
};  

class wrecking_priate : public pirate {
    public:
    int harm(cruise &boat) {
        boat.count_down_lives(20);
        boat.breakdown();
    }
    string get_type() {
        return "Wreckers";
    }
};

pirate * pirate_maker(const int turns) {
    if (turns % 5 == 0)
    {
        return new killer_pirate;
    }
    else if (turns % 2 == 0)
    {
        return new wrecking_priate;
    }
    return nullptr;
}