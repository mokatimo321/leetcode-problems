class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int i = 1, j = 0;
        
        st.push(pushed[0]);
        
        while(j < popped.size()) {
            if(i == pushed.size() && st.top() != popped[j]) {
                return false;
            }
            if(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else {
                st.push(pushed[i]);
                i++;
            }
        }
        
        return true;
        
    }
};