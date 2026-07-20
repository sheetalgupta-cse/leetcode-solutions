class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min =nums[0];
        int max = nums[0];
        for(int i=0; i<nums.size(); i++){
            if(max < nums[i]){
                max = nums[i];
            } else if(min > nums[i]){
                min = nums[i];
            }
        }
        return gcd(max, min);

        
    }
};