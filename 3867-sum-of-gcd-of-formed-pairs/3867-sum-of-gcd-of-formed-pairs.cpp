class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans =0;
        int mxi=0;
        int n=nums.size();
        vector<int> prefixGcd(n);
        for(int i=0;i<n;i++){
            mxi=max(mxi,nums[i]);
            int x= gcd(nums[i],mxi);
            prefixGcd[i]=x;
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0,j=n-1;
        while(i<j){
            int x= gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
            ans+=x;
        }
        return ans;
        
    }
};