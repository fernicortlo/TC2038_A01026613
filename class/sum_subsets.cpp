//backtracking
// set of s={2,3,4,7,9}
// the sum must be 9

#include <iostream>
#include <set>
#include <vector>

std::vector<int> s = {2,3,4,7,9};
int target = 9; 
//print the sum of the subsets
void printSubset(std::set<int> subset){
    std::cout << "{";
    for (int i:subset)
        std::cout << i << ",";
    std::cout << "}" << std::endl;
}

//backtracking
void backtracking(std::set<int> subset, int suma, int level, int current){
    if (suma == target){
        printSubset(subset);
        return;
    }
    if (suma > target)
        return;
    for (int i = current; i < s.size(); i++){
        subset.insert(s[i]);
        backtracking(subset, suma + s[i], level + 1, i + 1);
        subset.erase(s[i]);
    }
}

