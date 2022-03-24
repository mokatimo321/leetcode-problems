class Solution {
public:
    int numRescueBoats(vector<int>& mo, int limit, int bts = 0) {
      sort(mo.begin(), mo.end());
      for (int i = 0, j = mo.size() - 1; i <= j; bts++, j--) {
        if (mo[i] + mo[j] <= limit) ++i;
      }
      return bts;
    }
};