class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int temp = nums1.size() + nums2.size();
        double res = 0;
        int i = 0;
        int j = 0;
        int c = 0;
        if(temp%2 == 0) {
            int x = (temp-1)/2;
            int y = x+1;
            while(i < nums1.size() && j < nums2.size()) {
                if(nums1[i] < nums2[j]) {
                    if(c == x) {
                        //cout<<nums1[i]<<endl;
                        res += nums1[i];
                    }
                    if(c == y) {
                        //cout<<nums1[i]<<endl;
                        res += nums1[i];
                    }
                    c++;
                    i++;
                }
                else {
                    //c++;
                    if(c == x) {
                        //cout<<nums2[j]<<endl;
                        res += nums2[j];
                    }
                    if(c == y) {
                        //cout<<nums2[j]<<endl;
                        res += nums2[j];
                    }
                    c++;
                    j++;
                }
            }
            //cout<<i<<"---"<<j<<endl;
            if(nums1.size() != 0 && i <= nums1.size()-1) {
                while(i < nums1.size()) {
                    if(c == x) {
                        //cout<<nums1[i]<<endl;
                        res += nums1[i];
                    }
                    if(c == y) {
                        //cout<<nums1[i]<<endl;
                        res += nums1[i];
                    }
                    c++;
                    i++;
                }
                return res/2;
            }
            else {
                //cout<<"m"<<endl;
                while(j < nums2.size()) {
                    if(c == x) {
                        //cout<<nums2[j]<<endl;
                        res += nums2[j];
                    }
                    if(c == y) {
                        //cout<<nums2[j]<<endl;
                        res += nums2[j];
                    }
                    c++;
                    j++;
                }
                return res/2;
             }
        }
        int x = temp/2;
        //cout<<x<<endl;
        while(i < nums1.size() && j < nums2.size()) {
            //cout<<"h"<<endl;
            if(nums1[i] < nums2[j]) {
                if(c == x) {
                    res = nums1[i];
                    return res;
                }
                i++;
                c++;
            }
            else {
                if(c == x) {
                    res = nums2[j];
                    return res;
                }
                j++;
                c++;
            }
        }
        if(nums1.size() != 0 && i <= nums1.size()-1) {
            //cout<<"h"<<endl;
            while(i < nums1.size()) {
                if(x == c) {
                    res = nums1[i];
                    return res;
                }
                i++;
                c++;
            }
        }
        else {
            //cout<<j<<endl;
            while(j < nums2.size()) {
                if(x == c) {
                    res = nums2[j];
                    return res;
                }
                j++;
                c++;
            }
        }
        
        return 1;
    }
};