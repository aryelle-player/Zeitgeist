#include "apsmTrends.h"

#include <array>

void apsmTrends::increaseCount(std::string s, unsigned amount){
	//Pseudocode
	hashfunction(s)
		increase the hash by amount or add s to the hash table

	compare s.second (the amount of times it has been used) to the top10 array
		if s.second is used more than an element of the top10, swap s and that element.

}