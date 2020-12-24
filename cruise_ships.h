#ifndef CRUISE_SHIPS.H
#define CRUISE_SHIPS.H

#include <string>

using namespace std;

struct ship {
    int tourists = 100;
    string name;
};

class route {
    int difficulty;
    public:
    route(const int diff_in);
    void short_way();
    void long_way();
};

// this class does the following
//  - progresses the ship
//  - causes storms, diseases, and mechanical failures
//  - checks win conditions
class cruise {
    int turns,difficulty;
    route path;
    string start,destination;
    public:
    cruise(const int turns_in,const string start_in,const string dest_in,const int diff_in);
    int get_turns();
    void count_down_turns();
    void progress(const int route_choice);
    void disease();
    void breakdown();
    void win();
};

class pirate {
    public:
    virtual void harm() = 0;
    virtual void get_type() = 0;
    virtual ~pirate() {};
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