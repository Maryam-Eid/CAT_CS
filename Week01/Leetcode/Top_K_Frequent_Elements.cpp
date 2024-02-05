class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;

        unordered_map<int, int> frequencyMap;
        for (int num: nums) {
            frequencyMap[num]++;
        }

        vector <pair<int, int>> frequencyPairs(frequencyMap.begin(), frequencyMap.end());

        sort(frequencyPairs.begin(), frequencyPairs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k && i < frequencyPairs.size(); ++i) {
            result.push_back(frequencyPairs[i].first);
        }

        return result;
    }
};
