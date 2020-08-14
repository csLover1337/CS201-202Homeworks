/*
* File:   Team.h
* Author: Ömer Fatih Çelik 21601387
* CS201 2017 Fall HW1
* Created on November 6, 2017, 5:16 PM
*/

#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "Player.h"
using namespace std;

class Team {
public:
	Team();
	~Team();
	Team(const Team &toCopy);
	void operator = (const Team &T);
	void setName(string name);
	string getName();
	void setColor(string color);
	string getColor();
	void addPlayer(string playerName, string playerPosition);
	void removePlayer(string playerName);
	string getPlayerPosition(string playerName);
	int getRosterSize();
	int findPlayer(string name);
	void displayTeam();
private:
	string teamName;
	string teamColor;
	Player* roster;
	int rosterSize;
};

#endif /* TEAM_H */

