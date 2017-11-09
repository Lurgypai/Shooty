#include "stdafx.h"
#include "User.h"

User::User() : points(0) {
}

User::User(int recordPoints_, int farthestLevel_) : recordPoints(recordPoints_), farthestLevel(farthestLevel_), points(0) {
}

User::~User() {
}

void User::serialize() {
}

void User::unserialize() {
}

void User::setRecord(int recordPoints_) {
	recordPoints = recordPoints_;
}

void User::setCurrentPoints(int currentPoints_) {
	points = currentPoints_;
}

void User::incrementPoints(int morePoints) {
	points += morePoints;
}
