/*
* File:   Player.cpp
* Author: Omer Fatih Celik
*
* Created on December 4, 2017, 8:15 PM
*/

#include "Player.h"
#include <string>

using namespace std;

Player::Player() {
}

Player::Player(const Player& copy) {
	name = copy.name;
	position = copy.position;
}

void Player::operator=(const Player& right) {
	name = right.name;
	position = right.position;
}

void Player::setName(string playerName) {
	name = playerName;
}

string Player::getName() {
	return name;
}

void Player::setPosition(string playerPosition) {
	position = playerPosition;
}

string Player::getPosition() {
	return position;
}