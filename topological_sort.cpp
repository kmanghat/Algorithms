#include <bits/stdc++.h>
using namespace std;

/***
Topological sort using Kahn's algorithm
Given a graph this algorithm orders the vertices in the graph such that
if vertex u->v then u comes before v in the ordering.
The graph must be a Directed acyclic graph for this to be possible. If the 
graph contains a cylce then it is not possible to determine such an ordering.

Steps:
i) Find the indegree of all vertices(incoming edges)

ii) Keep track of vertices with indegree zero because only these can be used as
a valid starting node for the sort. (indegree != 0 ==> there is node before this one)

iii) Load all the vertices with indegree zero into a queue

iv) Process the queue, at each step the goal is to simulate removing 
the node at the top of the queue from the graph since it is already
in the sorted array. 
Instead of actually removing the node from the graph(computationaly expensive)
the indegree of all outgoing vertices can just be decremented by 1 since we 
are only interested in the indegree of vertices after the current vertex is removed.

v) After "removing" the vertex from the graph we check to see if any of the
vertices remaining have an indegree of 0, if it does we push it to the queue.
Like previously stated only when a vertex has an indegree of zero 
can it be the next node in the sorted array.

vi) Repeat till queue is empty

There are only two cases when the queue can be empty when there are no more vertices or when
all the unprocessed vertices in the graph have an indegree that is greater than 0.
If there is no vertex in the graph with indegree == 0 then intuitively we can say that there
is a cycle in the graph.

There are two possible results from this algorithm
a) The sorted array will contain exactly the same number of nodes in the graph in 
which case toposort was succesful and the graph contained no cycles.

b) The sorted array will contain less than the number of nodes in the graph which
means it was unsuccesful because the graph contained atleast one cycle.


Applications:
*Finding the prerequisites for a college class schedule
*Anything requires ordering of a graph

Problems on Leetcode.com
i) Course schedule
ii) Course schedule II
iii) Longest Increasing pathe in a matrix
***/


vector<int> topologicalSort(vector<vector<int>> graph)
{
    if(graph.empty())return {};
    
    vector<int> sorted_vertices;
    int vertices = graph.size();

    //Step 1: Find the indegree of each vertex in the graph
    vector<int> indegree(graph.size());
    for(auto vertex: graph)for(auto child:vertex) indegree[child]++;


    //Step 2&3: Load all vertices with indegree 0 in to the queue.
    queue<int> aQueue;
    for(int i = 0; i < vertices; i++)if(indegree[i] == 0)aQueue.push(i);

    while(!aQueue.empty())
    {
        int current_vertex = aQueue.front();aQueue.pop();

    //Step 4: Simulate removing the vertex by decrementing indegree of children by 1
        sorted_vertices.push_back(current_vertex);
        for(auto child:graph[current_vertex])
        {
            indegree[child]--;
    //Step 5: If indegree is 0 load it into the queue.
            if(indegree[child] == 0)aQueue.push(child);
        }
    }

    if(sorted_vertices.size() != vertices)return {};
    return sorted_vertices;
}

int main()
{
    vector<vector<int>> graph1{
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2}
    };
    vector<int> result1 = topologicalSort(graph1);
    vector<int> ans1 = {4,5,0,2,3,1};
    if(result1 == ans1)cout << "TEST 1 PASSED" << endl;
    else cout << "TEST 1 FAILED" << endl;


    vector<vector<int>> graph2{
        {1,2},
        {3,4},
        {3},
        {4},
        {}
    };
    vector<int> result2 = topologicalSort(graph2);
    vector<int> ans2 = {0,1,2,3,4};
    if(result2 == ans2)cout << "TEST 2 PASSED" << endl;
    else cout << "TEST 2 FAILED" << endl;


    vector<vector<int>> graph3{
        {1},
        {2},
        {3},
        {1},
    };
    vector<int> result3 = topologicalSort(graph3);
    vector<int> ans3 = {};
    if(result2 == ans2)cout << "TEST 3 PASSED" << endl;
    else cout << "TEST 3 FAILED" << endl;


    vector<int> result4 = topologicalSort({{}});
    vector<int> ans4 = {};
    if(result2 == ans2)cout << "TEST 4 PASSED" << endl;
    else cout << "TEST 4 FAILED" << endl;
    return 0;
}