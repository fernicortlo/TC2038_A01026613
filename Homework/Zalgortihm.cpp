// Z algorithm for pattern matching


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Z function
vector<int> Z_function(string pattern){
    int pattern_length = pattern.length();
    int left = 0;
    int right = 0;
    vector<int> Z_vector(pattern_length, 0);
    Z_vector[0]=0;

    for(int k=1; k<pattern_length; k++){
        if(k>right){
            left = right = k;
            while(right < pattern_length && pattern[right] == pattern[right-left]){
                right++;
            }
            Z_vector[k] = right-left;
            right--;
        }
        else{
            int k1 = k-left;
            if(Z_vector[k1] < right-k+1){
                Z_vector[k] = Z_vector[k1];
            }
            else{
                left = k;
                while(right < pattern_length && pattern[right] == pattern[right-left]){
                    right++;
                }
                Z_vector[k] = right-left;
                right--;
            }
        }
    }
    return Z_vector;
}


//main
int main (){
    std::string pattern_test = "ABABCABABABD";

    std::vector<int> vector_test1 = Z_function(pattern_test);
    
    for(int i=0; i<vector_test1.size(); i++){
        std::cout << vector_test1[i] << " ";
    }

    return 0;
}
