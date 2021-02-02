#ifndef CRUISE_SHIPS.H
#define CRUISE_SHIPS.H

#include <string>

using namespace std;

const char *names[10] = {"St. Thomas ","Toucan ","Tazmanian ","Virgin ",
                        "Nohea ","Khalua ","Lulea ","Fort Cox ","Moana ","Tiki "};
const char *other_names[10] = {"Great ","Grand ","Rich ","Tropics ","Blue ",
                             "Getaway ","Resort ","Destination ","Dune ","Paradise "};
const char *identifiers[10] = {"Island","Islands","Archipelago","Cliffs",
                              "Isle","Isla","Point","Peninsula","Isthmus","Lagoon"};

struct ship {
    int tourists = 100;
    int turns;
    int score = 0;
    string name;
};

struct location {
    string name;
};

class route {
    int halfway;
    public:
    route(const int halfway_in);
    void way(cruise &player_cruise,bool long_way);
};

// this class does the following
//  - progresses the ship
//  - causes storms, diseases, and mechanical failures
//  - checks win conditions
class cruise {
    int difficulty;
    ship * boat;
    route * path;
    string start,destination;
    public:
    cruise(const string start_in,const string dest_in,const int diff_in);
    int get_turns();
    void count_down_turns(const int decrement);
    void count_down_lives(const int decrement);
    void progress(const int route_choice);
    void disease();
    void breakdown();
    void storm();
    bool win();
};

class pirate {
    public:
    virtual int harm(cruise &boat) = 0;
    virtual string get_type() = 0;
    virtual ~pirate() {};
};

pirate * pirate_maker(const int turns);

static const int ENCOUNTER_PIRATES = .07;
static const int ENCOUNTER_STORM = .06;
static const int ENCOUNTER_DISEASES = .1;
static const int ENCOUNTER_MECH_FAILURE = .08;

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