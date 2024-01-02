class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>answer;
        

    for (const auto& query : queries) {
        int k = query[0];
        int trimi = query[1];
        std::vector<std::pair<std::string, int>> indexedTrimmedNums;

        // Trim the numbers in 'nums' to their rightmost 'trimi' digits and store them with their indices
        for (int i = 0; i < nums.size(); ++i) {
            std::string trimmed = nums[i].substr(std::max(0, (int)nums[i].size() - trimi));
            indexedTrimmedNums.emplace_back(trimmed, i);
        }

        // Sort the trimmed numbers and find the kth smallest number's index
        std::sort(indexedTrimmedNums.begin(), indexedTrimmedNums.end());

        // Find the index of the kth smallest trimmed number in the original 'nums'
        int index = indexedTrimmedNums[k - 1].second;
        answer.push_back(index);
    }

    return answer;
    }
};