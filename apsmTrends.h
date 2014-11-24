#include "Trends.h"
#include <array>
#include <string>

class apsmTrends : public Trends {
public:
	apsmTrends(){
		std::array<std::pair<std::string, unsigned int>, 10> topTen;

	}

	virtual void increaseCount(std::string s, unsigned amount);
	virtual std::string getNthPopular(unsigned int n);


  };

