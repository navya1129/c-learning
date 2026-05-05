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
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        queue<Node*>q;
        unordered_map<int,Node*>m;
        Node* res = nullptr;
        q.push(node);
        while(!q.empty()){
            Node* a = q.front();
            q.pop();
            Node* n;
            if(m.find(a->val) == m.end()){
                 n = new Node(a->val);
                m[a->val] = n;
            }
            else{
                n = m[a->val];
            }
            if(res == nullptr) res = n;
            vector<Node*>nei;
            for(auto it: a->neighbors){
                if(m.find(it->val) != m.end()){
                    nei.push_back(m[it->val]);
                }
                else{
                    Node* n = new Node(it->val);
                    m[it->val] = n;
                    q.push(it);
                    nei.push_back(n);
                }
            }
            n->neighbors = nei;
        }
        return res;
    }
};