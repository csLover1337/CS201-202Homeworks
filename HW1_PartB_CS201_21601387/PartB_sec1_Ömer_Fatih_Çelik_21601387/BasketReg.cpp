/*
* File:   BasketReg.cpp
* Author: Omer Fatih Celik
*
* Created on November 11, 2017, 11:21 PM
*/

#include "BasketReg.h"
#include <string>
#include <cstring>
#include <iostream>
#include "Team.h"
using namespace std;



BasketReg::BasketReg() {
	BasketReg::teamNo = 0;
	BasketReg::teams = new Team[teamNo];
}

BasketReg::~BasketReg() {
	delete[] teams;
}

BasketReg::BasketReg(const BasketReg &systemToCopy) {
	teamNo = systemToCopy.teamNo;
	teams = new Team[teamNo];
	for (int i = 0; i < teamNo; i++) {
		teams[i] = systemToCopy.teams[i];
	}
}

void BasketReg::operator =(const BasketReg &right) {
	teamNo = right.teamNo;
	Team* temp = teams;
	teams = new Team[teamNo];
	for (int i = 0; i < teamNo; i++)
		teams[i] = right.teams[i];
	delete[] temp;
}

void BasketReg::addTeam(string teamName, string teamColor) {
	if (findTeam(teamName) != -1)
		cout << "Error: Team already exist!" << endl;
	else {
		Team* temp = teams;
		int newTeamNo = teamNo + 1;
		Team *newTeams = new Team[newTeamNo];
		for (int i = 0; i < teamNo; i++)
			newTeams[i] = teams[i];
		teamNo = newTeamNo;
		teams = newTeams;
		teams[teamNo - 1].setName(teamName);
		teams[teamNo - 1].setColor(teamColor);
		delete[] temp;
	}
}

void BasketReg::removeTeam(string teamName) {
	int index = findTeam(teamName);
	if (index == -1)
		cout << "Error: Team " << teamName << " can't be found!" << endl;
	else {
		int newTeamNo = teamNo - 1;
		Team *newTeams = new Team[newTeamNo];
		for (int i = 0; i < teamNo; i++) {
			if (i != index && i < index)
				newTeams[i] = teams[i];
			else if (i != index && i > index)
				newTeams[i - 1] = teams[i];
		}
		teamNo = newTeamNo;
		delete[]teams;
		teams = newTeams;
	}
}

void BasketReg::displayAllTeams() {
	if (teamNo == 0)
		cout << "--EMPTY--" << endl;
	else {
		for (int i = 0; i < teamNo; i++)
			cout << "The team number " << i + 1 << " is: " << teams[i].getName() << ", " << teams[i].getColor() << endl;
	}
}

int BasketReg::findTeam(string teamName) {
	int len;
	for (int i = 0; i < teamNo; i++) {
		len = teams[i].getName().length();

		if (teamName.length() != len) {
			;
		}
		else {
			int correctLetters = 0;
			for (int a = 0; a < len; a++) {
				if (tolower((teams[i].getName())[a]) == tolower(teamName[a]))
					correctLetters++;
			}
			if (correctLetters == len)
				return i;
		}
	}
	return -1;
}

void BasketReg::addPlayer(string teamName, string playerName, string playerPosition) {
	if (findTeam(teamName) == -1)
		cout << "Error: Team " << teamName << " doesn't exist!" << endl;
	else {
		int index = findTeam(teamName);
		teams[index].addPlayer(playerName, playerPosition);
	}
}

void BasketReg::removePlayer(string teamName, string playerName) {
	if (findTeam(teamName) == -1)
		cout << "Error: Team " << teamName << " doesn't exist!" << endl;
	else {
		int index = findTeam(teamName);
		teams[index].removePlayer(playerName);
	}
}

void BasketReg::displayTeam(string teamName) {
	if (findTeam(teamName) == -1)
		cout << "Error: Team " << teamName << " doesn't exist!" << endl;
	else {
		int index = findTeam(teamName);
		teams[index].displayTeam();
	}
}

void BasketReg::displayPlayer(string playerName) {
	cout << playerName << ":" << endl;
	if (teamNo == 0)
		cout << "--EMPTY--" << endl;
	else {
		for (int i = 0; i < teamNo; i++) {
			if (teams[i].findPlayer(playerName) > -1) 
				cout << teams[i].getPlayerPosition(playerName) << ", " << teams[i].getName() << ", " << teams[i].getColor() << endl;
		}
	}
}