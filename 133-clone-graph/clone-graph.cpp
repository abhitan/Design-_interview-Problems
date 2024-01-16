/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
     unordered_map<Node*,Node*>mp;
     
     void dfs(Node* node, Node* cloned_node)
     {
         for(Node* n:node->neighbors)
         {
             if(mp.find(n) == mp.end())
             {
                 Node* clone = new Node(n->val);
                 mp[n] = clone;
                 cloned_node->neighbors.push_back(clone);
                 dfs(n,clone);
             }
             else
             {
                cloned_node->neighbors.push_back(mp[n]);
             }
         }
     }

    Node* cloneGraph(Node* node) {
        // sabse pehle cloned node banao
        if(!node) return NULL;
        Node* cloned_node = new Node(node->val);
        // ab iski mapping kro original node ke saath
        mp[node] = cloned_node;
        // run dfs on the nodes
        dfs(node,cloned_node);
        return cloned_node;
    }
};