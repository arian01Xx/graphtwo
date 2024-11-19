#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

 class SolutionSixteen{
 public:
 	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted){
 		unordered_map<int,vector<int>> graph;
 		unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

 		vector<bool> visited(n, false);

 		for(const auto& edge: edges){
 			graph[edge[0]].push_back(edge[1]);
 			graph[edge[1]].push_back(edge[0]);
 		}
 		int reachableCount=0;
 		queue<int> q;
 		q.push(0);
 		visited[0]=true;
 		while(!q.empty()){
 			int node=q.front();
 			q.pop();
 			reachableCount++;
 			for(int neighbor: graph[node]){
 				if(!visited[neighbor] && restrictedSet.find(neighbor)==restrictedSet.end()){
 					visited[neighbor]=true;
 					q.push(neighbor);
 				}
 			}
 		}
 		return reachableCount;
 	}
 /*
 Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
 */
 };

 int main(){
 	return 0;
 }