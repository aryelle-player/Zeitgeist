#include "apsmTrends.h"
#include <unordered_map>
#include <array>


//it looks like the unordered_map class already has a swap method
void apsmTrends::swap(std::pair<std::string, unsigned int>, int){

}


/*
* If the string "s" has not been added to the data structure yet, add it, and set its count to "amount"
* If the string "s" already has an entry in your data structure, just increase the count by "amount"
*
* Usually, "amount" will be equal to 1. See main.cpp for an example of how it is used.
*/
void apsmTrends::increaseCount(std::string s, unsigned amount){
	if (wordTable.find(s).first == s) {
		wordTable.find(s).second+=amount;
		//need to update topTen
	}
	
	if (wordTable.find(s) == NULL){
		wordTable.emplace(s, amount);
	}
	
	
	//Pseudocode
	hashfunction(s)
		increase the hash by amount or add s to the hash table

		compare s.second(the amount of times it has been used) to the top10 array
		if s.second is used more than an element of the top10, swap s and that element.

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

}


/*
* Return the total number of UNIQUE strings in the list. This will NOT be equal to the number of
* times increaseCount has been called, because sometimes you will add the same string to the
* data structure more than once. This function is useful when looping through the results
* using getNthPopular. If you do getNthPopular(numEntries()-1), it should get the least popular item
*/
unsigned int apsmTrends::numEntries(){

}

}