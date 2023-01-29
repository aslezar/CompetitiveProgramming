#include <unordered_map>
#include <list>
using namespace std;
class LFUCache
{
    int cap;
    int minimumfreq;
    unordered_map<int, list<pair<int, int>>> freq;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> data;

public:
    LFUCache(int capacity)
    {
        LFUCache::cap = capacity;
        minimumfreq = 0;
    }

    int get(int key)
    {
        const auto it = data.find(key);
        if (it == data.end())
            return -1;
        const int f = it->second.first;
        const auto it2 = it->second.second;
        const pair<int, int> kv = *it2;
        freq[f].erase(it2);
        if (freq[f].empty() && minimumfreq == f)
            ++minimumfreq;
        freq[f + 1].push_back({key, kv.second});
        data[key] = {f + 1, --freq[f + 1].end()};
        return kv.second;
    }

    void put(int key, int value)
    {
        if (cap <= 0)
            return;
        const auto it = data.find(key);
        if (it != data.end())
        {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (cap == data.size())
        {
            data.erase(freq[minimumfreq].front().first);
            freq[minimumfreq].pop_front();
        }
        minimumfreq = 1;
        freq[1].push_back({key, value});
        data[key] = {1, --freq[1].end()};
    }
};