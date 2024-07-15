#include <bits/stdc++.h>
using namespace std;

//Defanging an IP Address
//TC - O(N), SC - O(N)
string defangIP(string address){
    int index = 0;
    string ans;

    while(index < address.size()){
        if (address[index] = '.'){
            ans  += "[.]"; //direct assignment is not allowed. we need to append characters in string.
        }
        else {
            ans += address[index];
        }
        index++;
    }
    return ans;
}




// String Rotated by 2 Places
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    void rotateCW(string &s){
        char c = s[s.size()-1];
        int index = s.size()-2;
        
        while (index >= 0){
            s[index+1] = s[index];
            index--;
        }
        s[0] = c;
    }
    
    void rotateACW(string &s){
        char c = s[0];
        int index = 1;
        
        while (index < s.size()){
            s[index-1] = s[index];
            index++;
        }
        s[s.size()-1] = c;
    }
    
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size() != str2.size()){
            return 0;
        }
        
        string clockwise = str1, anticlockwise = str1;
        
        rotateCW(clockwise);
        rotateCW(clockwise);
        
        if (clockwise == str2){
            return 1;
        }
        
        rotateACW(anticlockwise);
        rotateACW(anticlockwise);
        
        if (anticlockwise == str2){
            return 1;
        }
        return 0;
    }

};

//Check if the sentence is Pangram
class Solution {
public:
    bool checkIfPangram(string sentence) {
     vector <bool> alpha(26, 0);
     for (int i=0; i<sentence.size(); i++){
        int index = sentence[i]-'a';

        alpha[index] = 1;
     }

     for (int i=0; i<26; i++){
        if (alpha[i] == 0) {
            return 0;
        }
     }
     return -1;
        
    }
};

int main(){

    return 0;
}