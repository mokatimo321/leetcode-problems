class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        int temp = 0;
        map<int, int> :: iterator itr;
        for(itr = mp.begin();itr != mp.end();itr++) {
            int val = itr->second;
            itr->second = temp;
            temp += val;
        }
        for(int i = 0;i<nums.size();i++) {
            cout<<mp[nums[i]]<<endl;
            nums[i] = mp[nums[i]];
        }
        return nums;
    }
};