/*
* File:   Player.h
* Author: Omer Fatih Celik
*
* Created on November 10, 2017, 8:15 PM
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
public:
	Player();
	Player(const Player& orig);
	void operator=(const Player &right);
	void setName(string playerName);
	string getName();
	void setPosition(string playerPosition);
	string getPosition();
private:
	string name;
	string position;
};

#endif /* PLAYER_H */

