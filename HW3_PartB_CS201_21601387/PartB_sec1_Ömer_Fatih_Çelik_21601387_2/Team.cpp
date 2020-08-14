/*
* File:   Team.cpp
* Author: Ömer Fatih Çelik 21601387
* CS201 2017 Fall HW1
* Created on December 4, 2017, 8:16 PM
*/

#include "Team.h"
#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Team::Team() {
	playerNo = 0;
	head = NULL;
}

Team::~Team() {
	if (head != NULL) {
		Node* temp;
		for (int i = 0; i < playerNo; i++) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}
}

Team::Team(const Team& copy) {
	teamName = copy.teamName;
	teamColor = copy.teamColor;
	playerNo = copy.playerNo;
	if (copy.head == NULL)
		head = NULL;
	else {
		head = new Node;
		Node* inCheck = copy.head;
		Node* temp = head;
		for (int i = 0; i < playerNo; i++) {
			head->p = inCheck->p;
			inCheck = inCheck->next;
			if (i + 1 < playerNo)
				head->next = new Node;
			head = head->next;
		}
		head = temp;
	}
}

void Team::operator =(const Team& T) {
	teamName = T.teamName;
	teamColor = T.teamColor;

	if (head != NULL || playerNo > 0) {
		Node* temp;
		for (int i = 0; i < playerNo; i++) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	playerNo = T.playerNo;
	if (T.head == NULL)
		head = NULL;
	else {
		head = new Node;
		Node* inCheck = T.head;
		Node* temp = head;
		for (int i = 0; i < playerNo; i++) {
			head->p = inCheck->p;
			inCheck = inCheck->next;
			if (i + 1 < playerNo)
				head->next = new Node;
			head = head->next;
		}
		head = temp;
	}
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
	if (findPlayer(playerName) != NULL)
		cout << "Error: Player " << playerName << " is already in team " << teamName << "!" << endl << endl;
	else {
		Node* newNode = new Node;
		newNode->p.setName(playerName);
		newNode->p.setPosition(playerPosition);

		if (head == NULL)
			head = newNode;
		else {
			Node* temp = head;
			head = newNode;
			newNode->next = temp;
		}
		playerNo++;
	}
}

void Team::removePlayer(string playerName) {
	if (findPlayer(playerName) == NULL)
		cout << "Error: Player " << playerName << " doesn't exist in team " << teamName << "!" << endl << endl;
	else {
		if (playerNo == 1) {
			delete head;
			head = NULL;
		}
		else {
			Node* toRemove = findPlayer(playerName);

			if (head == toRemove) {
				head = toRemove->next;
				delete toRemove;
			}
			else {
				Node* inCheck = head;
				for (int i = 0; i < playerNo; i++) {
					if (inCheck->next == toRemove) {
						inCheck->next = toRemove->next;
						delete toRemove;
						break;
					}
					inCheck = inCheck->next;
				}
			}
		}
		playerNo--;
	}
}

string Team::getPlayerPosition(string playerName) {
	if (findPlayer(playerName) == NULL)
		cout << "Error: Player " << playerName << " doesn't exist in team " << teamName << "!" << endl << endl;
	else 
		return findPlayer(playerName)->p.getPosition();
}

int Team::getRosterSize() {
	return playerNo;
}

Team::Node* Team::findPlayer(string name) {
	if (playerNo == 0 || head == NULL)
		return NULL;
	else {
		size_t len;
		int correctLetters = 0;
		Node* inCheck = head;

		for (int i = 0; i < playerNo; i++) {
			len = inCheck->p.getName().length();

			if (name.length() == len) {
				for (size_t a = 0; a < len; a++) {
					if (tolower((inCheck->p.getName())[a]) == tolower(name[a]))
						correctLetters++;
				}
				if (correctLetters == len)
					return inCheck;
			}
			inCheck = inCheck->next;
		}
	}
	return NULL;
}

void Team::displayTeam() {
	cout << teamName << ", " << teamColor << endl;
	if (playerNo == 0)
		cout << "--EMPTY--" << endl;
	else {
		Node* inCheck = head;
		for (int i = 0; i < playerNo; i++) {
			cout << inCheck->p.getName() << ", " << inCheck->p.getPosition() << endl;
			inCheck = inCheck->next;
		}
	}
	cout << endl;
}
