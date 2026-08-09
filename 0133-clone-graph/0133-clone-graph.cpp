class Solution {
    Node* dfs(Node* node,unordered_map<Node*, Node*>& visited){
        if(visited.find(node)!=visited.end()){
        return visited[node];
        }

        Node* clone = new Node(node->val);
        visited[node] = clone;

    //For each neighbor of original:
    // clone that neighbor (recursively)
    // add that clone to my list of neighbors

    for(Node* neighbor:node->neighbors){
        clone->neighbors.push_back(dfs(neighbor,visited));
    }
    return clone;
    }   

public:
    Node* cloneGraph(Node* node) {
       if(!node)return nullptr;
       unordered_map<Node*, Node*>visited;
       return dfs(node,visited);
    }
};