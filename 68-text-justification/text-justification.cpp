class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> result;
        int i = 0;

        while (i < words.size()) 
        {
            int j = i, lineWidth = 0;

            // Find the words that can fit in the current line
            while (j < words.size() && 
                    lineWidth + words[j].length() + (j - i) <= maxWidth) 
            {
                lineWidth += words[j].length();
                j++;
            }

            int numWords = j - i;
            int totalSpaces = maxWidth - lineWidth;

            // Build the current line
            string line = words[i];
            
            // If it's the last line or only one word in the line
            if (numWords == 1 || j == words.size()) 
            {
                for (int k = i + 1; k < j; k++) 
                {
                    line += " " + words[k];
                }

                line += string(maxWidth - line.length(), ' '); // Pad with spaces
            } 
            
            else 
            {
                int spacesBetweenWords = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int k = i + 1; k < j; k++) 
                {
                    int spaces = (k - i <= extraSpaces) ? 
                        spacesBetweenWords + 1 : spacesBetweenWords;
                    line += string(spaces, ' ') + words[k];
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};