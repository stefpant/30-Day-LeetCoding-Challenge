class Solution {
public:
    int countElements(vector<int>& arr) {
        int res = 0;
        map<int, int> ordarr;
        for(auto &i : arr)//insert elements in ordered map and count them
            ordarr[i]++;
        for( auto &i : ordarr )//for every element in map, if found it's next add it's count
            if( ordarr.find(i.first+1) != ordarr.end() ) res += i.second;
        return res;
    }
};
