#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getLength(ListNode *head) {
        int len = 0;
        while(head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = getLength(head);
        int parts = length / k;
        int currentPart = 1;
        ListNode *newHead = nullptr;
        ListNode *temp = head;
        ListNode *lastTail = nullptr;
        while(currentPart <= parts) {
            pair<ListNode*, ListNode*> nodes = reverseKelements(temp, k);
            if(newHead == nullptr) {
                newHead = nodes.first;
            }
            if(lastTail != nullptr) {
                lastTail->next = nodes.first;
            }
            lastTail = temp;
            temp = nodes.second;
            currentPart++;
        } 
        if(temp != nullptr)
            lastTail->next = temp;
        return newHead;
    }

    // Returns the tail of the old list, head of the starting new list
    pair<ListNode*, ListNode*> reverseKelements(ListNode* head, int k) {
        int i = 0;
        ListNode *temp = head;
        ListNode *prev = nullptr;

        while(i < k) {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            i++;
        }
        return {prev, temp};
    }
};

ListNode* convertToLL(vector<int> &elements) {
    if(elements.size() == 0) {
        return nullptr;
    }
    ListNode *head = new ListNode(elements[0]);
    ListNode *temp = head;
    for(int i = 1; i < elements.size(); i++) {
        temp->next = new ListNode(elements[i]);
        temp = temp->next;
    }
    return head;
}

void printLL(ListNode *head) {
    cout << "[";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]";
}

int main() {
    int t;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> elements(n);
        for(int i = 0; i < n; i++) {
            cin >> elements[i];
        }
        Solution s;
        ListNode *head = convertToLL(elements);
        printLL(head);
        cout << "\n";
        ListNode *newHead = s.reverseKGroup(head, k);
        cout << "Result: ";
        printLL(newHead);
        cout << "\n";
    }
    return 0;
}