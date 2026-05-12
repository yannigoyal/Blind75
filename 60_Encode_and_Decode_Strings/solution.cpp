/*
Encoding:
Store each string as:
length + "/:" + actual string

Decoding:
Read length till "/:",
convert it to integer,
then extract next 'length' characters.

TC: O(N)
SC: O(N)
*/
string encode(vector<string>& arr) {
		string encodeStr = "";
		for (int i = 0 ; i <arr.size(); i++) {
			encodeStr += to_string(arr[i].size());
			encodeStr += "/:";
			encodeStr += arr[i];
		}
		return encodeStr;
	}
	
vector<string> decode(string& s) {
    vector<string> ans;
    int i = 0;
    while (i<s.size()) {
        string len = "";
        while (!(s[i] == '/' && s[i + 1] == ':')) {
            len += s[i];
            i++;
        }
        int length = stoi(len);
        i += 2;
        string word = s.substr(i, length);
        ans.push_back(word);
        i += length;
    }
    
    return ans;
}