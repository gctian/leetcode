/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/word-ladder-ii
@Language: C++
@Datetime: 17-02-12 13:04
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string> > ans;
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        int dsize = dict.size(), len = start.length();
        unordered_map<string, vector<string> > next;
        unordered_map<string, int> vis;
        queue<string> q;
        vector<string> path;
        ans.clear();
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {
            string s = q.front(); q.pop();
            if (s == end) break;
            int step = vis[s];
            vector<string> snext;
            for (int i = 0; i < len; i++) {
                string news = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    news[i] = c;
                    if (c == s[i] || dict.find(news) == dict.end()) continue;
                    auto it = vis.find(news);
                    if (it == vis.end()) {
                        q.push(news);
                        vis[news] = step + 1;
                    }
                    snext.push_back(news);
                }
            }
            next[s] = snext;
        }
        path.push_back(start);
        dfspath(path, next, vis, start, end);
        return ans;
    }
    void dfspath(vector<string> &path,  unordered_map<string, vector<string> > &next,
                 unordered_map<string, int> &vis, string now, string end){
        if (now == end) ans.push_back(path);
        else {
            auto vec = next[now];
            int visn = vis[now];
            for (int i = 0; i < vec.size(); i++) {
                if (vis[vec[i]] != visn + 1) continue;
                path.push_back(vec[i]);
                dfspath(path, next, vis, vec[i], end);
                path.pop_back();
            }
        }
    }
};