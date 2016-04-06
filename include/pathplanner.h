#ifndef pathplanner_h
#define pathplanner_h

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>

#include <sbpl/headers.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits>
#include <string>



using namespace std;

struct envState{

float x; //x location of the state in meters
float y; //y location of that state in meters
float th; //theta at that state

};

class d2Exitplanner
{
public:

	d2Exitplanner(const char* envName, const char* motPrim);

	void createFootprint();
	void initializeEnv();
	//set env start goal
	void initializePlanner(SBPLPlanner*& planner, 
                       int start_id, int goal_id,
                       double initialEpsilon, 
                       bool bsearchuntilfirstsolution);

	bool plan();

	void populateGoals();

	std::vector<int> getSpotCosts();

private:

	char* envCfgFilename; //environment file name
	char* motPrimFilename; //motion primitives
	vector<sbpl_2Dpt_t> perimeter; //define the perimeter of the robot
	EnvironmentNAVXYTHETALAT env; //the environment file
	// SBPLPlanner* planner;
	// vector<int> solution_stateIDs; //vector containing the solution 
	
	std::vector<int> spotCosts; //store costs for all spots

	envState start;
	std::vector<envState> goal; //collection of all goals

	double initialEpsilon = 5.0;
    bool bsearchuntilfirstsolution = false;
    double allocated_time_secs = 5.0;



};

#endif