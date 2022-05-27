class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        vector<int> target;
        for(int i = 0;i<nums1.size();i++) {
            mp[nums1[i]] = 1;
        }
        for(int i = 0;i<nums2.size();i++) {
            mp[nums2[i]] += 2;
            if(mp[nums2[i]] == 3) {
                target.push_back(nums2[i]);
            }
            else if(mp[nums2[i]] == 4) {
                mp[nums2[i]] -= 2;
            }
        }
        for(int i = 0;i<nums3.size();i++) {
            mp[nums3[i]] += 3;
            if(mp[nums3[i]] == 4 || mp[nums3[i]] == 5) {
                target.push_back(nums3[i]);
                //mp[nums3[i]] = 3;
            }
        }
        return target;
    }
};