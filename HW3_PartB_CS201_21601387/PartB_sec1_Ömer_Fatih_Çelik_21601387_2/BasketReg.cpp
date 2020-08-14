/*
* File:   BasketReg.cpp
* Author: Omer Fatih Celik
*
* Created on December 4, 2017, 8:21 PM
*/

#include "BasketReg.h"
#include <string>
#include <cstring>
#include <iostream>
#include "Team.h"
using namespace std;



BasketReg::BasketReg() {
	teamNo = 0;
	head = NULL;
}

BasketReg::~BasketReg() {
	if (head != NULL) {
		Node* inCheck = head;
		Node* temp;
		for (int i = 0; i < teamNo; i++) {
			temp = inCheck->next;
			delete inCheck;
			inCheck = temp;
		}
	}
}

BasketReg::BasketReg(const BasketReg &systemToCopy) {
	teamNo = systemToCopy.teamNo;
	if (systemToCopy.head == NULL)
		head = NULL;
	else {
		head = new Node;
		Node* inCheck = systemToCopy.head;
		Node* temp = head;
		for (int i = 0; i < teamNo; i++) {
			head->t = inCheck->t;
			inCheck = inCheck->next;
			if (i + 1 < teamNo)
				head->next = new Node;
			head = head->next;
		}
		head = temp;
	}
}

void BasketReg::operator =(const BasketReg &right) {
	if (head != NULL || teamNo > 0) {
		Node* temp;
		for (int i = 0; i < teamNo; i++) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	teamNo = right.teamNo;
	if (right.head == NULL)
		head = NULL;
	else {
		Node* inCheck = right.head;
		head = new Node;
		Node* temp = head;
		for (int i = 0; i < teamNo; i++) {
			head->t = inCheck->t;
			if (i + 1 < teamNo)
				head->next = new Node;
			head = head->next;
			inCheck = inCheck->next;
		}
		head = temp;
	}
}

void BasketReg::addTeam(string teamName, string teamColor) {
	if (findTeam(teamName) != NULL)
		cout << "Error: Team " << teamName << " already exist!" << endl << endl;
	else {
		Node* newNode = new Node;
		newNode->t.setName(teamName);
		newNode->t.setColor(teamColor);

		if (head == NULL)
			head = newNode;
		else {
			Node* temp = head;
			head = newNode;
			head->next = temp;
		}
		teamNo++;
	}
}

void BasketReg::removeTeam(string teamName) {
	if (findTeam(teamName) == NULL)
		cout << "Error: Team " << teamName << " doesn't exist!" << endl << endl;
	else {
		if (teamNo == 1) {
			delete head;
			head = NULL;
		}
		else {
			Node* toRemove = findTeam(teamName);

			if (head == toRemove) {
				head = toRemove->next;
				delete toRemove;
			}
			else {
				Node* inCheck = head;
				for (int i = 0; i < teamNo; i++) {
					if (inCheck->next == toRemove) {
						inCheck->next = toRemove->next;
						delete toRemove;
						break;
					}
					inCheck = inCheck->next;
				}
			}
		}
		teamNo--;
	}
}

void BasketReg::displayAllTeams() {
	if (head == NULL) {
		cout << "--EMPTY--" << endl << endl;
		return;
	}

	Node* inCheck = head;
	cout << "Teams:" << endl;
	for (int i = 0; i < teamNo; i++) {
		cout << inCheck->t.getName() << ", " << inCheck->t.getColor() << endl;
		inCheck = inCheck->next;
	}
	cout << endl;
}

BasketReg::Node* BasketReg::findTeam(string teamName) {
	if (teamNo == 0 || head == NULL)
		return NULL;
	else {
		size_t len;
		int correctLetters = 0;
		Node* inCheck = head;

		for (int i = 0; i < teamNo; i++) {
			len = inCheck->t.getName().length();

			if (teamName.length() == len) {
				for (size_t a = 0; a < len; a++) {
					if (tolower((inCheck->t.getName())[a]) == tolower(teamName[a]))
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

void BasketReg::addPlayer(string teamName, string playerName, string playerPosition) {
	if (findTeam(teamName) == NULL)
		cout << "Error: Team " << teamName << " doesn't exist!" << endl;
	else 
		findTeam(teamName)->t.addPlayer(playerName, playerPosition);
}

void BasketReg::removePlayer(string teamName, string playerName) {
	if (findTeam(teamName) == NULL)
		cout << "Error: Team " << teamName << " doesn't exist!" << endl;
	else 
		findTeam(teamName)->t.removePlayer(playerName);
}

void BasketReg::displayTeam(string teamName) {
	if (findTeam(teamName) == NULL)
		cout << "Error: Team " << teamName << " doesn't exist!" << endl;
	else 
		findTeam(teamName)->t.displayTeam();
}

void BasketReg::displayPlayer(string playerName) {
	cout << playerName << ":" << endl;
	if (teamNo == 0)
		cout << "--EMPTY--" << endl;
	else {
		Node* inCheck = head;
		for (int i = 0; i < teamNo; i++) {
			if (inCheck->t.findPlayer(playerName) != NULL)
				cout << inCheck->t.findPlayer(playerName)->p.getPosition() << ", " << inCheck->t.getName() << ", " << inCheck->t.getColor() << endl;
		}
	}
	cout << endl;
}