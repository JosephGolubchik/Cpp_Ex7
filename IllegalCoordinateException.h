#pragma once

#include "Coordinate.h"
#include <sstream>
#include <string>

class IllegalCoordinateException {
	int x;
	int y;
public:
	IllegalCoordinateException(int x, int y): x(x),y(y) {}
	
	std::string theCoordinate() const { 
		std::ostringstream s;
    	s << x << "," << y;
    	return s.str();
	}
};

