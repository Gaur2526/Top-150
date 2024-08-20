Problem Statement Break Down :

1. words : an array of strings, where each string is a word.
2. maxWidth : an integer representing the maximum width of each line.
3. For each line, pack as many words as possible without exceeding maxWidth. A word cannot be split between lines.
4. a) Each line must be exactly maxWidth characters long.
   b) Extra spaces should be distributed as evenly as possible between words.
   c) If there are gaps (spaces between words) that cannot be evenly distributed, the leftmost gaps should get more spaces than the rightmost ones.
5. a) The last line should be left-justified.
   b) No extra spaces should be inserted between words on the last line; instead, all extra spaces should be added to the end of the line.

Solution : 

// Optimised approach 

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // Step 1: Determine the range of words for the current line
            int lineLength = words[i].length();
            int j = i + 1;
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            // Step 2: Build the current line
            int gaps = j - i - 1;
            string line = "";

            // If it's the last line or there is only one word in the line, left-justify
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // Fill the remaining space with spaces
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } else {
                // Fully justify the line
                int totalSpaces = maxWidth - lineLength;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spacePerGap + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }

            result.push_back(line);
            i = j; // Move to the next line
        }

        return result;
    }
};

Time complexity : O(n)
Space complexity : O(m) where m is the length of the input string
