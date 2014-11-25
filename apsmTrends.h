#include "Trends.h"
#include <unordered_map>
#include <array>
#include <unordered_map>

class apsmTrends : public Trends {
public:
<<<<<<< HEAD
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();

protected:
	std::array<std::pair<unsigned int, std::string>, 10> topTen;
	std::unordered_map<std::pair<std::string, unsigned int>> alphabetical;
	//i declared these as variables rather than making a constructor
	//brinkman said we don't need a constructor really
	//the problem with this is that i don't know how to finish it
	//if you go into the cpp api and lookup the unordered_map container
	//you'll be able to see how it's supposed to work
  };
=======
    apsmTrends(){
		std::array<std::pair<std::string, unsigned int>, 10> topTen;
        std::unordered_map<std::pair<std::string, unsigned int>> wordTable;
	}
    
	virtual void increaseCount(std::string s, unsigned amount);
	virtual std::string getNthPopular(unsigned int n);
    
private:
    virtual void swap(std::pair<std::string, unsigned int>, int);
};
>>>>>>> 4de76c698e5e3df79dec09ae20bf5b05759af0e4

