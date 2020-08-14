/*
* File:   Team.h
* Author: Ömer Fatih Çelik 21601387
* CS201 2017 Fall HW3
* Created on December 4, 2017, 8:16 PM
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
	void displayTeam();
	struct Node {
		Player p;
		Node* next;
	};
	Node* findPlayer(string name);
private:
	Node* head;
	int playerNo;
	string teamName;
	string teamColor;
};

#endif /* TEAM_H */

