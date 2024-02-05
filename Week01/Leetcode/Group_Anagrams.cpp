class Solution {
public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        vector <vector<string>> result;   // To store the final result.
        vector <vector<char>> signatures; // To store the sorted signatures of each string.

        // Iterate through each string in the input vector.
        for (const string &str: strs) {
            // Create a signature by sorting the characters of the string.
            vector<char> signature(str.begin(), str.end());
            sort(signature.begin(), signature.end());

            // Check if a group with the same signature already exists.
            vector < vector < char >> ::iterator
            it = find(signatures.begin(), signatures.end(), signature);
            if (it != signatures.end()) {
                // Append to an existing group.
                result[it - signatures.begin()].push_back(str);
            } else {
                // Create a new group.
                signatures.push_back(signature);
                result.push_back({str});
            }
        }

        return result;
    }
};
