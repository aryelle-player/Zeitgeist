#include "Trends.h"
#include <unordered_map>
#include <array>
#include <string>

class apsmTrends : public Trends {
public:
    apsmTrends(){
		std::array<std::pair<std::string, unsigned int>, 10> topTen;
        std::unordered_map<std::pair<std::string, unsigned int>> wordTable;
	}
    
	virtual void increaseCount(std::string s, unsigned amount);
	virtual std::string getNthPopular(unsigned int n);
    
private:
    virtual void swap(std::pair<std::string, unsigned int>, int);
};

