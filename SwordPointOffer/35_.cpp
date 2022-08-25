#include "leetcode.hpp"

class Solution {
  public:
  unordered_map<Node*, Node*> cachedNode;
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }
    if (!cachedNode.count(head)) {
      Node* headNew = new Node(head->val);
      cachedNode[head] = headNew;
      headNew->next = copyRandomList(head->next);
      headNew->random = copyRandomList(head->random);
    }
    return cachedNode[head];
  }
  Node* copyRandomList_2(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }
    for (Node* node = head; node != nullptr; node = node->next) {
      Node* nodenew = new Node(node->val);
      nodenew->next = node->next;
      node->next = nodenew;
    }
    for (Node* node = head; node != nullptr; node = node->next->next) {
      Node* nodenew = node->next;
      nodenew->random = (node->random != nullptr) ? node->random->next : nullptr;
    }
    Node* headnew = head->next;
    for (Node* node = head; node != nullptr; node = node->next) {
      Node* nodenew = node->next;
      node->next = node->next->next;
      nodenew->next = (nodenew->next != nullptr) ? nodenew->next->next : nullptr;
    }
    return headnew;
  }
};
