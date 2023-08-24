/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>m;

    Node* copyRandomList(Node* head) 
    {
        if(!head)   return NULL;
        if(m.count(head)) return m[head];

        Node* temp = new Node(head->val);
        m[head]=temp;

        temp->next=copyRandomList(head->next);
        temp->random=copyRandomList(head->random);

        return temp;
    }
};