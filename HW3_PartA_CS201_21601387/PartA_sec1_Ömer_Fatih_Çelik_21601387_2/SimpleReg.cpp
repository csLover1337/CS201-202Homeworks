#include "SimpleReg.h"
#include <string>
#include <iostream>
using namespace std;


SimpleReg::SimpleReg() {
	teamNo = 0;
	head = NULL;
}

SimpleReg::~SimpleReg() {
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

SimpleReg::Node* SimpleReg::findTeam(string teamName) {
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

void SimpleReg::addTeam(string teamName, string teamColor) {
	if (findTeam(teamName) != NULL) {
		cout << "Error: Team " << teamName << " already exist!" << endl << endl;
		return;
	}
	
	Node* newNode = new Node;
	newNode->t.setName(teamName);
	newNode->t.setColor(teamColor);

	if (head == NULL)
		head = newNode;
	else {
		Node* temp = head;
		head = newNode;
		newNode->next = temp;
	}
	teamNo++;
}

void SimpleReg::removeTeam(string teamName) {
	if (findTeam(teamName) == NULL) {
		cout << "Error: Team " << teamName << " doesn't exist!" << endl << endl;
		return;
	}
	
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

void SimpleReg::displayAllTeams() {
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