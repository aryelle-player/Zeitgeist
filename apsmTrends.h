#include "Trends.h"
#include <array>

class apsmTrends : public Trends {
public:

	virtual void increaseCount(std::string s, unsigned amount);
	virtual std::string getNthPopular(unsigned int n);


  };

