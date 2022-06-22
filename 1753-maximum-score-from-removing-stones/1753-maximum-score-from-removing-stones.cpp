class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        //declare the priority queue
        priority_queue<int> q;
        
        //init by pushing all the three piles
        q.push(a);
        q.push(b);
        q.push(c);
        
        //Rsult Counter
        int cnt = 0; 
        
        //game stops when empty piles are more than 1
        while(q.size() > 1) {
            //update the counter
            cnt++;
            
            //for size --> 3
            if(q.size() == 3) {
                a = q.top();
                q.pop();
                a--;
                
                b = q.top();
                q.pop();
                
                c = q.top();
                q.pop();
                c--;
                
                if(a > 0) {
                    q.push(a);
                }
                
                if(b > 0) {
                    q.push(b);
                }
                
                if(c > 0) {
                    q.push(c);
                }
                
                //cout<<a<<"----"<<b<<"--------"<<c<<endl;
                
            }
            else {
                a = q.top();
                q.pop();
                a--;
                
                b = q.top();
                q.pop();
                b--;
                
                if(a > 0) {
                    q.push(a);
                }
                
                if(b > 0) {
                    q.push(b);
                }  
                
                //cout<<a<<"----"<<b<<"--------"<<0<<endl;
                
            }
            
            //cout<<q.size()<<endl;
            
        }
        
        return cnt;
        
    }
};