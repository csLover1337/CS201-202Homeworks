#include "SimpleTeam.h"

Team::Team() {}
Team::~Team() {}


string Team::getColor() {
	return color;
}

string Team::getName() {
	return name;
}

void Team::setColor(string teamColor) {
	color = teamColor;
}

void Team::setName(string teamName) {
	name = teamName;
}