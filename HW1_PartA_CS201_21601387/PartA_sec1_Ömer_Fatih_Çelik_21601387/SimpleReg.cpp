#/* 
 * File:   SimpleReg.cpp
 * Author: Ömer Fatih Çelik 21601387
 * CS201 2017 Fall HW1
 * Created on November 6, 2017, 5:16 PM
 */

#include "SimpleReg.h"
#include <string>
#include <cstring>
#include <iostream>
#include "SimpleTeam.h"
using namespace std;



SimpleReg::SimpleReg() {
	SimpleReg::teamNo = 0;
	SimpleReg::teams = new Team[teamNo];
}

void SimpleReg::addTeam(string teamName, string teamColor) {
	if (findTeam(teamName) != -1)
		cout << "Error: Team already exist!" << endl;
	else {
		Team* temp = teams;
		int newTeamNo = teamNo + 1;
		Team* newTeams = new Team[newTeamNo];
		for (int i = 0; i < teamNo; i++)
			newTeams[i] = teams[i];
		teamNo = newTeamNo;
		teams = newTeams;
		teams[teamNo - 1].setName(teamName);
		teams[teamNo - 1].setColor(teamColor);
		delete[] temp;
	}
}

void SimpleReg::removeTeam(string teamName) {
	int index = findTeam(teamName);
	if (index == -1)
		cout << "Error: Team " << teamName << " can't be found!" << endl;
	else {
		Team* temp = teams;
		int newTeamNo = teamNo - 1;
		Team* newTeams = new Team[newTeamNo];
		for (int i = 0; i < teamNo; i++) {
			if (i != index && i < index) {
				newTeams[i].setColor(teams[i].getColor());
				newTeams[i].setName(teams[i].getName());
			}
			else if (i != index && i > index) {
				newTeams[i-1].setColor(teams[i].getColor());
				newTeams[i-1].setName(teams[i].getName());
			}
		}
		teamNo = newTeamNo;
		teams = newTeams;
		delete[] temp;
	}
}

void SimpleReg::displayAllTeams() {
	if (teamNo == 0)
		cout << "--EMPTY--" << endl;
	else {
		for (int i = 0; i < teamNo; i++)
			cout << "The team number " << i + 1 << " is: " << teams[i].getName() << ", " << teams[i].getColor() << endl;
	}
}

int SimpleReg::findTeam(string teamName) {
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