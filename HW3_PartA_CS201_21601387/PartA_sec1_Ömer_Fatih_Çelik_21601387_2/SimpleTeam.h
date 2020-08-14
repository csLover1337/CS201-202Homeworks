#pragma once
#include <string>
using namespace std;
class Team
{
public:
	Team();
	~Team();
	string getColor();
	string getName();
	void setColor(string);
	void setName(string);
private:
	string name;
	string color;
};

