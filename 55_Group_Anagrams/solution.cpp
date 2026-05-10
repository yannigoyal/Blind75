/*
Sort each string so anagrams get same key.
Store original strings in hashmap using sorted string as key.
Finally push all grouped anagrams into answer.

TC: O(n * k log k)
SC: O(n * k)
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> umap;

    for(auto x: strs) {
        string temp  =x;
        sort(x.begin(), x.end());

        umap[x].push_back(temp);
    }

    for(auto x: umap) {
        ans.push_back(x.second);
    }
    return ans;
}