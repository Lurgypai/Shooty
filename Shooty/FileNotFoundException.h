#pragma once
#include "stdafx.h"

class FileNotFoundException : public std::exception {
	virtual const char* what() const throw() {
		return "A file was not found.";
	}
};