/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/topological-sorting
@Language: C++
@Datetime: 17-02-11 03:35
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> bfs(vector<DirectedGraphNode*> graph){
        vector<DirectedGraphNode*> res;
        map<DirectedGraphNode*,int> indegree;
        stack<DirectedGraphNode*> zeros;
        for(DirectedGraphNode* node:graph){
            for(DirectedGraphNode* edge:node->neighbors){
                indegree[edge]++;
            }
        }
        //添加入度为0的顶点
        for(DirectedGraphNode* node:graph){
            if(indegree[node] == 0){
                zeros.push(node);
            }
        }
        
        //输出一个入度为0 的顶点
        while(!zeros.empty()){
            DirectedGraphNode* temp = zeros.top();
            zeros.pop();
            res.push_back(temp);
            for(DirectedGraphNode* node:temp->neighbors){
                indegree[node]--;
                if((indegree[node]) == 0){
                    //入栈
                    zeros.push(node);
                }
            }
        }
        return res;
        
    }
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        return bfs(graph);
    }
};