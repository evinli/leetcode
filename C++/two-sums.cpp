// Time: O(n^2)
// Space: O(1)
// Helpful links: 
    // https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/?fbclid=IwAR2uNQAiekti5bYhKBT-H80gEkteL2YJXb7HBOQwMeaVYsNuonycYRuZKCk

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums.at(i) + nums.at(j)) == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};


// Time: O(n)
// Space: O(n)
// Helpful links:
    // https://www.programiz.com/cpp-programming/unordered-map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums.at(i)) != umap.end()) { // faster than umap.count()
                return {umap.at(target - nums.at(i)), i};
            }
            umap.insert({nums.at(i), i}); // u-map doesn't allow duplicate keys 
        }
        return {};
    }
};


