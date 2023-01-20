class Solution {
public:
    void backtrack(vector<int>& nums,vector<int>& seq, set<vector<int>>& result,int index)
    {
        if(index>=nums.size())
        {
            if(seq.size()>1)
                {result.insert(seq);}
            return;
        }
        if(seq.empty() || seq.back()<=nums[index])
        {
            seq.push_back(nums[index]);
            backtrack(nums,seq,result,index+1);
            seq.pop_back();
        }
        backtrack(nums,seq,result,index+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        set<vector<int>> ans;
        vector<int> seq;
        backtrack(nums,seq,ans,0);

        return vector(ans.begin(),ans.end());
    }
};
