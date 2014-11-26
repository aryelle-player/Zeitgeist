#include "apsmTrends.h"
#include <unordered_map>
#include <array>


//it looks like the unordered_map class already has a swap method
void apsmTrends::swap(std::pair<std::string, unsigned int> p, int index){
    if(index == 9) {
        topTen.swap(p, topTen[index]);
        if(topTen[index].second > topTen[index-1].second) {
            swap(topTen[index], index-1);
        }
    }
    if(index > 0) {
        topTen.swap(topTen[index+1], topTen[index]);
        if(topTen[index].second > topTen[index-1].second) {
            swap(topTen[index], index-1);
        }
    }
    else {
        topTen.swap(topTen[index+1], topTen[index]);
    }
}


/*
* If the string "s" has not been added to the data structure yet, add it, and set its count to "amount"
* If the string "s" already has an entry in your data structure, just increase the count by "amount"
* Usually, "amount" will be equal to 1. See main.cpp for an example of how it is used.
*/
void apsmTrends::increaseCount(std::string s, unsigned amount){
	if (wordTable.count(s) > 0) {
		wordTable.find(s)->second += amount;
        
        if(wordTable.find(s)->second > topTen[9]->second) {
            swap(std::pair<std::string, unsigned int>(s, wordTable.find(s)->second), 9);
        }
		//compare s.second(the amount of times it has been used) to the top10 array
		//if s.second is used more than an element of the top10, swap s and that element.
	}
	
	if (wordTable.count(s) == 0){
		wordTable.emplace(s, amount);
        if(numEntries()<10) {
            topTen[numEntries()] = std::pair<std::string, unsigned int>(s, wordTable.find(s)->second);
        }
	}
}

/*
* Return the nth most popular item, based on its count. If there is a tie, return the string that
* comes first according to the the < operator for strings (that is, comes first alphabetically). If n is
* out of range, return ""
*/
std::string apsmTrends::getNthPopular(unsigned int n){
	if (n <= 10 && n > 0){
		return topTen[n - 1].second;
	}

	if (n > 10){
		//search hashtable for hash n
		//return the associated string
	}

	return "";
}


/*
* Return the count for the given string. 0 if not present, of course.
*/
unsigned int apsmTrends::getCount(std::string s){
	if (wordTable.count(s) == 0) { return 0; }
	
	return wordTable.find(s)->second;
}


/*
* Return the total number of UNIQUE strings in the list. This will NOT be equal to the number of
* times increaseCount has been called, because sometimes you will add the same string to the
* data structure more than once. This function is useful when looping through the results
* using getNthPopular. If you do getNthPopular(numEntries()-1), it should get the least popular item
*/
unsigned int apsmTrends::numEntries(){
	return 0;
}
