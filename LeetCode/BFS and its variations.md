Hello Everyone,  

BFS is a pretty standard algorithm but in some problem we have to teak it slightly to solve the problem.  
In this post I have summarized all the different variants. Please let me know in comments if anything is missed.  

**Standard BFS** 

This is pretty standard, we use a queue and add unexplored node at each level until queue is empty.  
Why BFS always found shortest path:  
The very first time a node is discovered (unvisited node), its distance from the root node will always be shortest.  
For example we have a root and it has 3 neighbors , root to those neigbors have distance 1 and the same idea applies recursively for all undiscovered node.  
https://leetcode.com/problems/find-if-path-exists-in-graph/  
 
**0-1 BFS**

In standard BFS we have used queue but in this kind of problem we are prefering one path i.e. nodes with cost/value 0 over other node with value 1.  
So we use deque and if we get 0 we insert in front and if we get 1 we insert back.

Following problems can be practiced for 0-1 BFS.

Hard : https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
Medium: https://leetcode.com/problems/shortest-bridge/
Hard: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/


**Multi-source BFS**  

Generally we start BFS with a single source node and then traverse, in this class of problem we are given multiple source.
How example multiple target location are there and you have find nearest target location from each node.  
Real life example is multiple cities and some has police station, for each city find the nearest.  
So in these kind of problem put all the source node(some time destination node) and then start the BFS , the moment we find a city from polic station, we know that's nearest surely.  

https://leetcode.com/problems/walls-and-gates/
https://leetcode.com/problems/as-far-from-land-as-possible/
https://leetcode.com/problems/map-of-highest-peak/


**BFS with bitmasking**  
Generally in BFS we maintain a visited array/set to not-visit nodes which are already visited.  
In this class of problem, we can revisit the visited cell but this time when we visit we some new information (state).  
So eah cell is marked visited with both  state + cell_id.  

Sometime these problem can also be solved with DFS+Bitmasking + memoization.  

Example:
Hard: https://leetcode.com/problems/shortest-path-to-get-all-keys/

You start the BFS and dont just insert row,col in visited set, instead also insert how many keys have you collected so far, and while exploring neighbors check there mask also.  
BFS queue will have (row, col, mask ) for each entry.  
```
#define MAX_DIR (4)
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int K = 0;
        int start = 0;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, 0)));
        for(int i=0; i< m; ++i)
            for(int j =0; j < n ; ++j)
            {
                if(grid[i][j]=='@')
                    start = i*n+j;
                else if(grid[i][j]>='A' and grid[i][j]<='F')
                    ++K;
            }
        queue<pair<int, int>> q;
        q.push(make_pair(start, 0));
        visited[start/n][start%n][0] = true;
        int ans =0;
        int d[MAX_DIR+1] = {-1, 0, 1, 0, -1};
        while(!q.empty() ){
            int sz = q.size();
            for(int i =1; i <=sz; ++i){
                int t = q.front().first; 
                int r = t/n;
                int c = t%n;
                int mask = q.front().second;
                q.pop();
                if(mask == ((1<<K)-1))
                    return ans;
               
                for(int i =0; i<MAX_DIR; ++i){
                    int n_r = r + d[i];
                    int n_c = c + d[i+1];
                    int oned = (n_r*n)+n_c;
                    
                    if(n_r <0 or n_r >= m or n_c <0 or n_c >=n or grid[n_r][n_c]=='#')
                       continue;
                    int k = mask; // take a copy
                    if(grid[n_r][n_c] >='a')
                        k = k | (1<<(grid[n_r][n_c]-'a')); //set
                    else if(grid[n_r][n_c] >='A'){
                        if(! (k&(1<<(grid[n_r][n_c]-'A'))))
                            continue;
                    }
                     if(!visited[n_r][n_c][k]){
                         q.push(make_pair(oned, k));
                         visited[n_r][n_c][k] = true;
                     }
                }
            }
            ++ans;
            }
        return -1 ;
    }
};
```

Hard:  https://leetcode.com/problems/shortest-path-visiting-all-nodes/

**Bi-directional BFS (Bi-BFS)** 

In a standard BFS, algorithm starts from source and tries to reach to target location.  
We can visualize this as a growing circle where at each level the circle grows bigger and bigger.  
What we start from source as well as target and make alternating moves and the moment we find a common node processed in both direction, we know we are done.  
This greatly reduce the search time.  
If we consider
branching factor (**b**):  # of child nodes coming out of a node.  
depth(**d**):  How deep is the tree  
BFS = O(b^d)  
while Bi-BFS would take O(b^(d/2))  
since both forward and backward BFS run, we are exploring half of the exploration space.  


Similar logic can be applied to 
Dijkstra Algorithm (directed or undirected):  Since edges have weight associated to it, once you find a meeting point, see which node weight combination give cheapest cost.  
Directed graph (unweighted): Create a reverse copy of graph and explore similar as described above.

Practice Problem for Bi-BFS:
Almost any problem you have solved with BFS you can try Bi-BFS.  
Let's see an example
https://leetcode.com/problems/word-ladder/  
As you can see until forward AND backward queue are non-empty, I am doing a BFS run alternate forward and  backward.  
After BFS run I try to find an intersection of visited set of both direction, If anything common is found , we know shortest path has been found and we return it.  
Why -1 while return , because common node is found in both direction so we have subtract -1.
```
typedef enum  {
    FORWARD=0,
    BACKWARD,
    MAX_DIR
}DIR;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if( (wordSet.find(endWord)==wordSet.end()))
            return 0;
        
        set<string> node_set[MAX_DIR];
        queue<string> q[MAX_DIR];
        
        q[FORWARD].push(beginWord);
        q[BACKWARD].push(endWord);
        node_set[FORWARD].insert(beginWord);
        node_set[BACKWARD].insert(endWord);
        
        auto find_common_node =[&](set<string>& out){
            out.clear();
            set_intersection(node_set[FORWARD].begin(), node_set[FORWARD].end(),node_set[BACKWARD].begin(),node_set[BACKWARD].end(), inserter(out, out.begin()));
            return out;
        };
        
        auto bfs = [&](bool direction){
            int sz =q[direction].size();
            for(int k =0; k< sz; ++k){
               string node = q[direction].front();
                q[direction].pop();
                for(int i =0; i < node.size(); ++i){
                    for(char j ='a' ; j<='z'; ++j){
                        char old = node[i];
                        node[i] = j;
                        // new word should exist and unvisited
                        if( (wordSet.find(node)!=wordSet.end()) and
                           node_set[direction].find(node)==node_set[direction].end()
                           )
                        {
                            node_set[direction].insert(node);
                            q[direction].push(node);
                        }
                        node[i] = old;
                    }
                }
            }
        };
        
        set<string> out;
        int forward_level =1;
        int back_level =1;
        while(!q[BACKWARD].empty() and !q[FORWARD].empty()){
            
            find_common_node(out);
            if(out.size())
                return forward_level + back_level -1;
            
            bfs(FORWARD);
            ++forward_level;
            
            find_common_node(out);
            if(out.size())
                return forward_level + back_level -1;
            
            bfs(BACKWARD);
            ++back_level;
        }
        
        return 0;
    }
};
```

https://leetcode.com/problems/jump-game-iv/  
https://leetcode.com/problems/open-the-lock/  
https://leetcode.com/problems/shortest-bridge/  
https://leetcode.com/problems/minimum-genetic-mutation/  
https://leetcode.com/problems/escape-a-large-maze/  



Reference: 
https://en.wikipedia.org/wiki/Bidirectional_search  
https://www.coursera.org/learn/algorithms-on-graphs/lecture/atXR2/computing-the-distance  
https://www.youtube.com/watch?v=DINCL5cd_w0  



