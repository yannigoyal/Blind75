/*
Count frequency of each character for every string.
Create a unique key using character counts.
Strings with same frequency key are grouped together.

TC: O(n * k)
SC: O(n * k)
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> umap;

    for (string str : strs) {
        int freq[26] = {0};

        for (char ch : str) {
            freq[ch - 'a']++;
        }
        string key = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                key += char(i + 'a');
                key += to_string(freq[i]);
            }
        }
        umap[key].push_back(str);
    }

    for (auto x : umap) {
        ans.push_back(x.second);
    }
    return ans;
}