/*
* File:   SimpleTeam.h
* Author: �mer Fatih �elik 21601387
* CS201 2017 Fall HW1
* Created on November 6, 2017, 5:16 PM
*/

#ifndef SIMPLETEAM_H
#define SIMPLETEAM_H

#include <string>
using namespace std;

class Team {
public:
	Team();
	void setName(string name);
	string getName();
	void setColor(string color);
	string getColor();
private:
	string teamName;
	string teamColor;
};

#endif /* SIMPLETEAM_H */

