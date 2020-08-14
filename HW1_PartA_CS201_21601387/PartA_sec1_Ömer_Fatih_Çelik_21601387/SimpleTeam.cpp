/*
* File:   SimpleTeam.cpp
* Author: Ömer Fatih Çelik 21601387
* CS201 2017 Fall HW1
* Created on November 6, 2017, 5:16 PM
*/

#include "SimpleTeam.h"
#include <string>
using namespace std;

Team::Team() {}

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