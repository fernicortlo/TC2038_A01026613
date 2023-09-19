#include <iostream>
#include <vector>
#include <string>

//Prefix function

std::vector<int> prefixFunction(std::string pattern){
    int pattern_length = pattern.length();
    int i=1;
    int j=0;
    std::vector<int> prefixVector(pattern_length, 0);
    prefixVector[0]=0;

    while (i < pattern_length)
    {
        if (pattern[i] == pattern[j])
        {
            prefixVector[i] = j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0){
                prefixVector[i]=0;
                i++;
            }
            else
            {
                j=prefixVector[j-1];
            }
        }
        i++;
    }
    return prefixVector;
    
}

int main (){
    std::string pattern_test = "AABCACBAAC";

    std::vector<int> vector_test1 = prefixFunction(pattern_test);
    
    for(int i=0; i<vector_test1.size(); i++){
        std::cout << vector_test1[i] << " ";
    }

    return 0;
}

