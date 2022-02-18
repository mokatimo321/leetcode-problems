class Solution {
public:
    bool isValid(string s) {
       std::stack<int> st;
       for(int i = 0;i<s.length();i++) {
           
           
           if(int(s[i]) == 40) {
                st.push(int(s[i]));
            }
           else if(int(s[i]) == 41) {
               if(st.empty()) {
                   return false;
               }
               if(st.top() != 40) {
                   return false;
               }
               else {
                   st.pop();
               }
           }
           
           
           
           if(int(s[i]) == 123) {
               st.push(int(s[i]));
           }
           else if(int(s[i]) == 125) {
               if(st.empty()) {
                   return false;
               }
               if(st.top() != 123) {
                   return false;
               }
               else {
                   st.pop();
               }
           }       
           
           
           if(int(s[i]) == 91) {
               st.push(int(s[i]));
           }
           else if(int(s[i]) == 93) {
               if(st.empty()) {
                   return false;
               }
               if(st.top() != 91) {
                   return false;
               }
               else {
                   st.pop();
               }
           }
       }
        
        if(!st.empty()) {
            return false;
        }
        
        return true;
    }
};