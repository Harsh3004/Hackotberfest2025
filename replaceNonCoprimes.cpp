// Replace Non-Coprime Numbers in Array

class Solution {
    int GCD(int a,int b){
        if(b == 0)
            return a;
        
        return GCD(b,a%b);
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        s.push(nums[0]);

        for(int i = 1; i<n; i++){
            int top = s.top();
            int gcd = (nums[i] > top) ? GCD(nums[i],top) : GCD(top,nums[i]);
            if(gcd == 1){
                s.push(nums[i]);
            }else{
                long long lcm = (nums[i]/gcd) * top;
                while(!s.empty()){
                    int top = s.top();
                    int gcd2 = (lcm >= top) ? GCD(lcm,top) : GCD(top,lcm);
                    if(gcd2 != 1){
                        s.pop();
                        lcm *= (top/gcd2);
                    }else
                        break;
                }
                s.push(lcm);
            }
        }

        int size = s.size();
        vector<int> ans(s.size());
        for(int k = size-1; k>=0; k--){
            ans[k] = s.top();
            s.pop();
        }
        
        return ans;
    }
};
