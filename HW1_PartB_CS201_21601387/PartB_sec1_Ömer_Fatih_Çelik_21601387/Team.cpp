/*
* File:   Team.cpp
* Author: Ömer Fatih Çelik 21601387
* CS201 2017 Fall HW1
* Created on November 6, 2017, 5:16 PM
*/

#include "Team.h"
#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Team::Team() {
	rosterSize = 0;
	roster = new Player[rosterSize];
}

Team::~Team() {
	delete[] roster;
}

Team::Team(const Team& copy) {
	teamName = copy.teamName;
	teamColor = copy.teamColor;
	rosterSize = copy.rosterSize;
	roster = new Player[rosterSize];
	for (int i = 0; i < rosterSize; i++) {
		roster[i] = copy.roster[i];
	}
}

void Team::operator =(const Team& T) {
	teamName = T.teamName;
	teamColor = T.teamColor;
}

void Team::setName(string name) {
	teamName = name;
}

void Team::setColor(string color) {
	teamColor = color;
}

string Team::getColor() {
	return teamColor;
}

string Team::getName() {
	return teamName;
}

void Team::addPlayer(string playerName, string playerPosition) {
	if (findPlayer(playerName) > -1)
		cout << "Error: Player " << playerName << " is already in team " << teamName << "!" << endl;
	else {
		rosterSize++;
		Player* temp = roster;
		roster = new Player[rosterSize];
		for (int i = 0; i < rosterSize - 1; i++) {
			roster[i] = temp[i];
		}
		roster[rosterSize - 1].setName(playerName);
		roster[rosterSize - 1].setPosition(playerPosition);
		delete[] temp;
	}
}

void Team::removePlayer(string playerName) {
	if (findPlayer(playerName) == -1)
		cout << "Error: Player " << playerName << " doesn't exist in team " << teamName << "!" << endl;
	else {
		rosterSize--;
		Player* temp = roster;
		roster = new Player[rosterSize];
		int index = findPlayer(playerName);
		for (int i = 0; i < rosterSize + 1; i++) {
			if (i != index && i < index)
				roster[i] = temp[i];
			else if (i != index && i > index)
				roster[i - 1] = temp[i];
		}
		delete[] temp;
	}
}

string Team::getPlayerPosition(string playerName) {
	if (findPlayer(playerName) == -1)
		cout << "Error: Player " << playerName << " doesn't exist in team " << teamName << "!" << endl;
	else {
		int index = findPlayer(playerName);
		return roster[index].getPosition();
	}
}

int Team::getRosterSize() {
	return rosterSize;
}

int Team::findPlayer(string name) {
	int len;
	for (int i = 0; i < rosterSize; i++) {
		len = roster[i].getName().length();

		if (name.length() != len) {
			;
		}
		else {
			int correctLetters = 0;
			for (int a = 0; a < len; a++) {
				if (tolower((roster[i].getName())[a]) == tolower(name[a]))
					correctLetters++;
			}
			if (correctLetters == len)
				return i;
		}
	}
	return -1;
}

void Team::displayTeam() {
	cout << teamName << ", " << teamColor << endl;
	if (rosterSize == 0)
		cout << "--EMPTY--" << endl;
	else {
		for (int i = 0; i < rosterSize; i++) {
			cout << "Player " << i << ": " << roster[i].getName() << ", " << roster[i].getPosition() << endl;
			cout << endl;
		}
	}
}