class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        // Create a hash set to store unique normalized email addresses.
        unordered_set<string> uniqueEmails;

        for (const string& email : emails) 
        {
            // Split the email into local name and domain name.
            size_t atPos = email.find('@');
            string localName = email.substr(0, atPos);
            string domainName = email.substr(atPos + 1);

            // Normalize the local name by removing '.', and handling '+'
            string normalizedLocalName;
            for (char c : localName) 
            {
                if (c == '.') continue; // Skip '.' characters
                if (c == '+') break;    // Ignore rest of local name if '+' is encountered
                normalizedLocalName += c;
            }

            // Combine normalized local name and domain name to form the normalized email.
            string normalizedEmail = normalizedLocalName + '@' + domainName;

            // Add the normalized email to the hash set.
            uniqueEmails.insert(normalizedEmail);
        }

        // Return the count of unique normalized emails.
        return uniqueEmails.size();
    }
};
