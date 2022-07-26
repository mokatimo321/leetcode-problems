class TopVotedCandidate {
public:
    
    //this will store the person's id who is leading the election
    unordered_map<int, int> mp;
    vector<int> times;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        
        //we also need the times array
        this->times = times;
        
        unordered_map<int, vector<int>> lead;
        unordered_map<int, int> people;
        int mx = 0;
        for(int i = 0;i<times.size();i++) {
            //store the vote of the current person
            people[persons[i]]++;
            //get the maximum vote till now
            mx = max(mx, people[persons[i]]);
            //store the vote count to check if there is any duplicate
            lead[people[persons[i]]].push_back(persons[i]);
            //store the final lead at this time instant
            mp[times[i]] = lead[mx][lead[mx].size() - 1];
        }
        
    }
    
    int q(int t) {
        return mp[*--upper_bound(times.begin(), times.end(), t)];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */