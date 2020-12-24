#ifndef CRUISE_SHIPS.H
#define CRUISE_SHIPS.H

#include <string>

struct ship {
    int tourists = 100;
    string name;
};

// this class does the following
//  - progresses the ship
//  - causes storms, diseases, and mechanical failures
//  - checks win conditions
class cruise {
    int turns;
    string start,destination;
    public:
    cruise(const int turns_in,const string start_in,const string dest_in);
    int get_turns();
    void progress();
    void disease();
    void breakdown();
    void win();
};

class pirate {
    public:
    virtual void harm() = 0;
    virtual void get_type();
};

pirate * pirate_maker(const int turns);

#endif


// this is a game like oregon trail
// cli interactible, you start with 100 tourists and try to get 
// from point a to point b without killing everyone
// there can be diseases, storms, pirates and mechanical failures
//  - diseases will kill passengers over time
//  - storms will kill passengers or damage the ship
//  - mechanical failures will slow the ship
//  - pirates can bring all three depending on type
//  - you have to reach the finish line in under a certain 
//    number of turns or you run out of gas and lose