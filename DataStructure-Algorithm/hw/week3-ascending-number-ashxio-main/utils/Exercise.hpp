#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution{
public:
    bool areNumAscending(std::string s){
        // your code here ...
        vector<int> texts;
        for (int i = 0; i < s.size(); i++){
            if (isdigit(s[i])){
                int num = 0;
                while (i < s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                texts.push_back(num);
            }
        }
        for (int i = 1; i < texts.size(); i++){
            if (texts[i] <= texts[i - 1]){
                return false;
            }
        }
        return true;
    }
};
