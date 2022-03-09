Hello Everyone,  

BFS is a pretty standard algorithm but in some problem we have to teak it slightly to solve the problem.  
In this post I have summarized all the different variants. Please let me know in comments if anything is missed.  

## Standard BFS

This is pretty standard, we use a queue and add unexplored node at each level until queue is empty.  
Why BFS always found shortest path:  
The very first time a node is discovered (unvisited node), its distance from the root node will always be shortest.  
For example we have a root and it has 3 neighbors , root to those neigbors have distance 1 and the same idea applies recursively for all undiscovered node.  
https://leetcode.com/problems/find-if-path-exists-in-graph/  
 
## 0-1 BFS

In standard BFS we have used queue but in this kind of problem we are prefering one path i.e. nodes with cost/value 0 over other node with value 1.  
So we use deque and if we get 0 we insert in front and if we get 1 we insert back.

Following problems can be practiced for 0-1 BFS.


Lets see the working with an example problem.  
**Medium** : https://leetcode.com/problems/shortest-bridge/  
Here We will first try to find 1st island and that is our priority, so those priority cell are pushed in front.  
Next when we first get a '0' cell that surely means we are done finding our first island, so I will set a flag.  
Next lets increment the cost and try to find first **unvisited 1**  because that surely would be second island and if we get we know we find our 2nd island and return cost.  
Here i am using cost vector has dual purpose , first to record cost and second to find a unvisited set.  
An unvisited cell will have surely INT_MAX cost.  

Will show the working using a picture.  
![image](https://user-images.githubusercontent.com/20656683/157424737-076ea66a-f5a2-49c3-987e-7685f76bfe1d.png)
Orange Cell is first Island: during it processing we do get to see cell which has water , but we push them to back of queue and push 1 in front of queue.  
Thats why all 1 of first island are orange color and processed first.  
Next we process first blue cell i..e 0 , we know surely we are done with finding 1st island, and then aim is to find first 1 i..e green cell.  

**Main difference**
- Regular BFS we do level by level and hence we only traverse size of queue per level, in 0-1 BFS we dont do like that.  
- We use a cost matrix, while in standard BFS its not the case.  


```
#define MAX_DIR (4)
class Solution {
    vector<vector<int>> cost;
    deque<pair<int, int>> d;
    int n;
    void find_start(const vector<vector<int>>& grid){
        for(int i =0; i <n ; ++i){
            for(int j =0; j < n ; ++j)
            {
                if(grid[i][j]){
                    d.push_back(make_pair(i, j));
                    cost[i][j] = 0;
                    return;
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        cost.resize(n, vector<int>(n, INT_MAX));
        find_start(grid);
        bool first_island_found = false;
        while(!d.empty()){
            int x = d.front().first;
            int y = d.front().second;
            if(grid[x][y]==0) // that means we are done procesing first island
                first_island_found = true; // now we are going to always see 
            if(first_island_found and grid[x][y])
                return cost[x][y];
            d.pop_front();
            int dir[MAX_DIR+1] = {-1, 0, 1, 0, -1};
            for(int i =0; i<MAX_DIR; ++i){
                int n_x = x + dir[i];
                int n_y = y + dir[i+1];
                if(n_x >=0 and n_x < n and n_y>=0 and n_y <n and cost[n_x][n_y]==INT_MAX){
                    cost[n_x][n_y] = min(cost[n_x][n_y], cost[x][y]);
                    if(grid[n_x][n_y]==0)
                    {
                        ++cost[n_x][n_y]; // since we have to flip
                        d.push_back(make_pair(n_x, n_y));
                    }
                    else{
                        d.push_front(make_pair(n_x, n_y));
                    }
                }
            }
            
        }
        return 0;
    }
};
```

**Hard** : https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/  
In this problem , at each cell, a direction is printed where you can with cost 0 and if you have to go other direction you have to change the direction and that would cost 1.  
So we prefer those ne cell where the cost is 0 and push them to front of queue and other cell where we can reach with cost 1 is pushed back of queue.
In addition to this , we also maintain a cost matrix, so during exploration we check if the find a cheaper path, we update.  

```
#define MAX_DIR 4
class Solution {
    // UP, RIGHT, DOWN, LEFT
    int dir[MAX_DIR+1] = {-1, 0, 1, 0, -1};
    
    int getIndex(int i){
        if(i==1) 
            return 1;//RIGHT =1
        else if(i==2) 
            return 3;//LEFT = 3
        else if(i==3) 
            return 2; // DOWN = 2
        return 0;// UP =0
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int, int>> d;
        d.push_back(make_pair(0, 0));
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;
        while(!d.empty()){
            int v = d.front().first;
            int r = (d.front().second)/n;
            int c = (d.front().second)%n;
            d.pop_front();
            int move_cost[MAX_DIR] = {1, 1, 1, 1}; // Initially we mark that all 4 neighbouring direction need 1 cost to go.  
            move_cost[getIndex(grid[r][c])] = 0; // Then we check what is marking on this cell , and make that direction as 0.  
            if(r==m-1 and c==n-1)
                return cost[r][c];
            for(int i=0; i<MAX_DIR; ++i){
                int n_r = r + dir[i];
                int n_c = c + dir[i+1];
                if(n_r >=0 and n_r<m and 
                   n_c >=0 and n_c<n and
                   v < cost[n_r][n_c]
                  )
                {
                    cost[n_r][n_c] = v; // update the cost
                     if(move_cost[i])
                     {
                         cost[n_r][n_c]++; // Since an extra step of cost 1 is required because the direction is different.
                         d.push_back(make_pair(cost[n_r][n_c], n_r*n+n_c));  // move cost is 1 so push back
                     }
                    else
                        d.push_front(make_pair(cost[n_r][n_c], n_r*n+n_c)); // move cost is 0 we push to front of queue.  
                }
            }
        }
        
        return 0;
    }
};
```

## Multi-source BFS

Generally we start BFS with a single source node and then traverse, in this class of problem we are given multiple source.
How example multiple target location are there and you have find nearest target location from each node.  
Real life example is multiple cities and some has police station, for each city find the nearest.  
So in these kind of problem put all the source node(some time destination node) and then start the BFS , the moment we find a city from polic station, we know that's nearest surely.  

Example: https://leetcode.com/problems/walls-and-gates/  
Initially we put all the gates in BFS queue and then start BFS.  
The very first room we encounter from gate and that is unvisited is surely cheapest one.  
So update the cost as 1 + current cell.  Thats all.  
```
#define MAX_DIR (4)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        int m = rooms.size();
        int n = rooms[0].size();
        for(int i =0; i < m ; ++i){
            for(int j =0; j < n ; ++j){
                if(rooms[i][j]==0)
                    q.push(make_pair(i, j));
            }
        }
        int dir [MAX_DIR+1] = {-1, 0, 1, 0, -1 };
        while(!q.empty()){
            int sz = q.size();
            for(int i =1; i <=sz; ++i){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j =0; j < MAX_DIR; ++j){
                    int n_x = x  + dir[j];
                    int n_y = y  + dir[j+1];
                    if(n_x >=0 and n_x <m and n_y >=0 and n_y < n and rooms[n_x][n_y]==INT_MAX){
                        rooms[n_x][n_y] = 1 + rooms[x][y];
                        q.push(make_pair(n_x, n_y));
                    }
                }
            }
        }
    }
};
```

https://leetcode.com/problems/as-far-from-land-as-possible/  
https://leetcode.com/problems/map-of-highest-peak/  


## BFS with bitmasking
Generally in BFS we maintain a visited array/set to not-visit nodes which are already visited.  
In this class of problem, we can revisit the visited cell but this time when we visit we some new information (state).  
So eah cell is marked visited with both  state + cell_id.  

Sometime these problem can also be solved with DFS+Bitmasking + memoization.  

Example:
Hard: https://leetcode.com/problems/shortest-path-to-get-all-keys/

You start the BFS and dont just insert row,col in visited set, instead also insert how many keys have you collected so far, and while exploring neighbors check there mask also. When you revisit an already visited cell, we check how many key have this time, if it is different from the time we previously visited cell, this is a new state and should be explored.   
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

## Bi-directional BFS (Bi-BFS)

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
After BFS run I try to find an intersection of visited set of both direction, If anything common is found , we know shortest path has been found and we return sum of level's.  
Why -1 while return , because common node is found in both direction so we have subtract -1.  
Similar try https://leetcode.com/problems/word-ladder-ii/  

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
https://leetcode.com/problems/minimum-genetic-mutation/  
Same problem as above except number , just some minor tweaks
```
typedef enum  {
    FORWARD=0,
    BACKWARD,
    MAX_DIR
}DIR;
class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord)==wordSet.end())
            return -1;
        
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
        char mutation [] ={'A', 'C', 'G', 'T'};
        auto bfs = [&](bool direction){
            int sz =q[direction].size();
            for(int k =0; k< sz; ++k){
               string node = q[direction].front();
                q[direction].pop();
                for(int i =0; i < node.size(); ++i){
                    for(int j =0; j < 4; ++j){
                        char old = node[i];
                        if(old==mutation[j])
                            continue;
                        node[i] = mutation[j];
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
        int forward_level =0;
        int back_level =0;
        while(!q[BACKWARD].empty() and !q[FORWARD].empty()){
            
            find_common_node(out);
            if(out.size())
                return forward_level + back_level ;
            
            bfs(FORWARD);
            ++forward_level;
            
            find_common_node(out);
            if(out.size())
                return forward_level + back_level ;
            
            bfs(BACKWARD);
            ++back_level;
        }
        
        return -1;
    }
};
```
https://leetcode.com/problems/jump-game-iv/  
https://leetcode.com/problems/open-the-lock/  
https://leetcode.com/problems/shortest-bridge/  

Reference: 
https://en.wikipedia.org/wiki/Bidirectional_search  
https://www.coursera.org/learn/algorithms-on-graphs/lecture/atXR2/computing-the-distance  
https://www.youtube.com/watch?v=DINCL5cd_w0  



