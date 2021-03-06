#include "apsmTrends.h"
#include <unordered_map>
#include <array>

apsmTrends::apsmTrends() {
    numWords = 0;
}

int* apsmTrends::grow(int* startIndex) {
	int arraySize = numEntries() * 2;
	int* tempArray = startIndex;
	startIndex = new int[arraySize];

	for(unsigned int i=0; i < numEntries(); i++) {
		startIndex[i] = tempArray[i];
	}

	return startIndex;
}

void apsmTrends::swap(std::pair<std::string, unsigned int> p, int index){
    if(index == 9) {
        (topTen.at(index)).swap(p);
        if(topTen[index].second > topTen[index-1].second) {
            swap(topTen[index], index-1);
        }
    }
    else if(index > 0) {
        (topTen.at(index)).swap(topTen[index+1]);
        if(topTen[index].second > topTen[index-1].second) {
            swap(topTen[index], index-1);
        }
    }
    else {
        (topTen.at(index)).swap(topTen[index+1]);
    }
}


/*
* If the string "s" has not been added to the data structure yet, add it, and set its count to "amount"
* If the string "s" already has an entry in your data structure, just increase the count by "amount"
* Usually, "amount" will be equal to 1. See main.cpp for an example of how it is used.
*/
void apsmTrends::increaseCount(std::string s, unsigned int amount){
	if (wordTable.count(s) > 0) {
		wordTable.find(s)->second += amount;
        
        if(wordTable.find(s)->second > topTen[9].second) {
            swap(std::pair<std::string, unsigned int>(s, wordTable.find(s)->second), 9);
        }
    }
	
	if (wordTable.count(s) == 0){
		wordTable.emplace(s, amount);
        numWords++;
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
		return (topTen.at(n - 1)).first;
	}

	if (n > 10){
		//do what smarterTrends does which is put them all
        //in an array, sort it, and then just use array[n]
		int* wordUsage = new int[50];
		//MAKE GROW METHOD	
		unsigned int wordUsageSize = 0;

		for(auto it = wordTable.begin(); it != wordTable.end(); it++) {
			if(wordUsageSize >= numEntries()) {
				wordUsage = grow(wordUsage);
			}
			//One of these should work?
			wordUsage[wordUsageSize] = it->second;
			//wordUsage += it->second;

			wordUsageSize++;
		}
		
		//Order wordUsage
		for(unsigned int i=0; i < wordUsageSize; i++) {
			for(unsigned int j=i; j < wordUsageSize; j++) {
				if(wordUsage[j] < wordUsage[i]) {
					int temp = wordUsage[j];
					wordUsage[j] = wordUsage[i];
					wordUsage[i] = temp;
				}
			}
		}

		//Go through, like the first for loop, but compare the nth
		//of wordUsage with the current pair's int, if equal, 
		//return the current pair's string
		for(auto it = wordTable.begin(); it != wordTable.end(); it++) {
			/*if(wordTable.find(it) == wordTable.end()) { 
				return "ERROR: The word was not found."; 
			}
			else 
			*/
			if(wordUsage[n] == it->second) {
				return it->first;
			}
		}
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
	return numWords;
}
