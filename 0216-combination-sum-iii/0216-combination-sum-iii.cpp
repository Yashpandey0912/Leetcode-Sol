class Solution {
public:

    vector<vector<int>> ans;
    vector<int> ds;

    void solver(int target, int k, int index)
    {
        if (k == 0)
        {
            if (target == 0)
                ans.push_back(ds);

            return;
        }

        for (int i = index; i <= 9; i++)
        {
            ds.push_back(i);

            solver(target - i, k - 1, i + 1);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        solver(n, k, 1);
        return ans;
    }
};