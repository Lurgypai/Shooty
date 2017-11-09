#pragma once
#include "stdafx.h"

//for saving and loading player info
class User {
public:
	User();
	User(int recordPoints_, int farthestLevel_);
	~User();
	void serialize();
	void unserialize();
	void setRecord(int recordPoints_);
	void setCurrentPoints(int currentPoints_);
	void incrementPoints(int morePoints);
	void reset();
private:
	int points;
	int recordPoints;
	int farthestLevel;
};