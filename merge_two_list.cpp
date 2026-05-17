#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prevA = nullptr;
        ListNode *afterB = nullptr;
        ListNode *curr = list1;
        int idx = 0;

        while (idx < a - 1) {
            curr = curr->next;
            idx++;
        }

        prevA = curr;
        curr = curr->next;

        while (idx < b) {
            ListNode *del = curr;
            curr = curr->next;
            delete del;
            idx++;
        }

        afterB = curr;

        prevA->next = list2;

        while (list2->next)
            list2 = list2->next;

        list2->next = afterB;

        return list1;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list1: 0 -> 1 -> 2 -> 3 -> 4 -> 5
    ListNode* list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    // Create list2: 1000000 -> 1000001 -> 1000002
    ListNode* list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    int a = 3;
    int b = 4;

    Solution obj;

    cout << "List1 before merge: ";
    printList(list1);

    cout << "List2: ";
    printList(list2);

    ListNode* result = obj.mergeInBetween(list1, a, b, list2);

    cout << "Merged List: ";
    printList(result);

    return 0;
}