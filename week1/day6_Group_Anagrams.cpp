class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //second solution-> using hashmap: 64ms
        //(first solution: use another vector of vectors,O(N) space and O(N^2) time : 1300ms :-/)
        unordered_map<string,vector<string>> umap;
        string temp;
        for(int i=0; i<strs.size(); i++){
            temp = strs[i];//sort chars of every string,then save same
            sort(temp.begin(), temp.end());//sorted string in a vector
            umap[temp].push_back(strs[i]);
        }
        vector<vector<string>> res = {};
        for ( auto &m : umap ) {
            res.push_back(m.second);
        }
        return res;
    }
};
