class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        if (stones.size() == 0)
            return 0;
        multiset<int> s;
        for (auto &&i : stones)
            s.insert(i);
        while (s.size() > 1)
        {
            auto it = prev(s.end());
            auto it2 = prev(it);
            if (*it != *it2)
                s.insert(*it - *it2);
            s.erase(it);
            s.erase(it2);
        }

        return *s.begin();
    }
};