#include <bits/stdc++.h>
using namespace std;

// Longest Palindrome
class Solution
{
public:
    int longestPalindrome(string s)
    {

        // making two arrays to store the frequency of lower and upper case alphabets
        vector<int> lower(26, 0), upper(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a')
            {
                lower[s[i] - 'a']++;
            }
            else
            {
                upper[s[i] - 'A']++;
            }
        }

        int count = 0;
        bool odd = 0;

        // lower
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] % 2 == 0)
            {
                count += lower[i];
            }
            else
            {
                count += lower[i] - 1;
                odd = 1;
            }

            // upper
            if (upper[i] % 2 == 0)
            {
                count += upper[i];
            }
            else
            {
                count += upper[i] - 1;
                odd = 1;
            }
        }
        return count + odd;
    }
};

// Sorting the Sentence
class Solution {
public:
    string sortSentence(string s) {
        // Initialize a vector to store words in correct positions
        vector<string> ans(10);
        string temp;
        int count = 0, index = 0;

        // Loop through each character in the string
        while (index < s.size()) {
            if (s[index] == ' ') {
                // Extract the position number and store the word in correct position
                int pos = temp[temp.size() - 1] - '0'; // Last character is the position
                temp.pop_back(); // Remove the position digit from the word
                ans[pos] = temp; // Store the word in its correct position
                temp.clear(); // Clear the temporary string for the next word
                count++;
            } else {
                temp += s[index]; // Add characters to the temporary string
            }
            index++;
        }
        
        // Handle the last word which might not be followed by a space
        if (!temp.empty()) {
            int pos = temp[temp.size() - 1] - '0';
            temp.pop_back();
            ans[pos] = temp;
            count++;
        }

        // Construct the final sorted sentence
        string result;
        for (int i = 1; i <= count; ++i) {
            result += ans[i];
            if (i != count) {
                result += " ";
            }
        }
        
        return result;
    }
};


int main()
{

    return 0;
}