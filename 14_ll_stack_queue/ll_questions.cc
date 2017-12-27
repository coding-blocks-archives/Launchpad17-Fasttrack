// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};


Node* createLL() {
    int x;
    Node* head = NULL;    // ALWAYS initialise pointers
    Node* tail = NULL;

    // head = addofFirstNode
    // tail = addOfLastNode

    while (true) {
        cin >> x;
        if (x == -1) break;

        // Creating a node
        // Without Ctor
        // Node* newNode = new Node;
        // (*newNode).data = x;    // newNode->data = x;
        // newNode->next = NULL;

        // with Ctor
        Node * newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void display(Node * head) {
    Node* curNode = head;

    while (curNode != NULL) {
        cout  << curNode->data << "-->";
        curNode = curNode->next;
    }
    cout << endl;
}


Node* midNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* mergeSortedLL(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data) {
        a->next = mergeSortedLL(a->next, b);
        return a;
    }

    b->next = mergeSortedLL(a, b->next);
    return b;

}

// Merge Sort Function
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }


    Node* mid = midNode(head);
    Node* a = head;
    Node* b = mid->next;

    // breaking the link
    mid->next = NULL;

    //sorting
    a = mergeSort(a);
    b = mergeSort(b);
    head = mergeSortedLL(a, b);
    return head;
}

// reverse a linked list
Node* reverseLL(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* remList = reverseLL(head->next);
    Node* tmp = remList;

    while (tmp && tmp->next) {
        tmp = tmp->next;
    }

    // if (tmp) tmp->next = head;
    tmp->next = head;   // list has atleast 2 nodes
    head->next = NULL;

    return remList;
}


// reverseOpt
Node* reverseOpt(Node* head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }

    Node* remList = reverseOpt(head->next);
    head->next->next = head;
    head->next = NULL;
    return remList;
}

Node* reverseIter(Node* head) {
    Node* cur = head;
    Node* prevNode  = NULL;

    while (cur) {
        Node* ahead = cur->next;
        cur->next = prevNode;
        prevNode = cur;
        cur = ahead;
    }

    return prevNode;
}


// BUBBLE SORT
int lengthLL(Node* head) {
    int cnt = 0;
    Node* cur = head;
    while (cur) {
        ++cnt;
        cur = cur->next;
    }
    return cnt;
}


Node* bubbleSortLL(Node* head) {
    int len = lengthLL(head);
    for (int i = 0; i < len - 1; ++i) {
        Node* cur = head;
        Node* prevNode = NULL;

        while (cur && cur->next) {
            Node* ahead = cur->next;
            if (cur->data > ahead->data) {
                // swapping has to be there
                if (cur == head) {
                    cur->next = ahead->next;
                    ahead->next = cur;
                    head = ahead;
                    prevNode = ahead;
                }
                else {
                    cur->next = ahead->next;
                    ahead->next = cur;
                    prevNode->next = ahead;
                    prevNode = ahead;
                }
            } else {
                // move all pointer ahead
                prevNode = cur;
                cur = ahead;
            }
        }
    }
    return head;
}


// detect Cycle
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }

    return false;
}


int main() {
    Node* head = createLL();

    // head = mergeSort(head);
    // display(head);

    // head = reverseLL(head);
    // display(head);

    // head = reverseOpt(head);
    // display(head);

    // head = reverseIter(head);
    // display(head);


    // head = bubbleSortLL(head);
    // display(head);

    // head->next->next->next->next->next = head->next->next;
    bool ans = detectCycle(head);
    cout << ans;



    return 0;
}