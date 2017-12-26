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

Node* insertAtPos(Node* head, int x, int pos) {
    Node * cur = head;

    // for(int i = 1; i < pos && cur->next != NULL; ++i){
    for (int i = 1; i < pos && cur->next; ++i) { // if exists
        cur = cur->next;
    }

    Node* nodeToBeInserted = new Node(x);

    // beginning
    if (pos == 0) {
        nodeToBeInserted->next = head;
        return nodeToBeInserted;

    }

    // not beginning
    Node * tmp = cur->next;
    nodeToBeInserted->next = tmp;
    cur->next = nodeToBeInserted;
    return head;
}

Node* deleteNode(Node* head, int pos) {
    Node * cur = head;
    for (int i = 1; i < pos - 1 && cur; ++i) {
        cur = cur->next;
    }

    if (pos == 0 ||cur == NULL) return head;

    // if beginning
    if (pos == 1) {
        Node* tmp = head->next;
        delete cur;
        return tmp;
    }

    Node* tmp = cur->next;
    if (tmp) cur->next = tmp->next;
    delete tmp;
    return head;
}

int findElement(Node* head, int elementToSearch){
    if (head == NULL) return -1;


    if (head->data == elementToSearch) return 0;

    int pos = findElement(head->next, elementToSearch);
    if (pos != -1) return pos + 1;
    return -1;

}

/*//HW
Node* findElement(Node* head, int elementToSearch){
    // return the node
    ;
}*/

Node* midNode(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int lengthLL(Node* head){
    int cnt = 0;
    Node* cur = head;
    while(cur){
        ++cnt;
        cur = cur->next;
    }
    return cnt;
}

// HW
Node* fifthFromLast(Node* head){

}

Node* mergeSortedLL(Node* a, Node* b){
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data){
        a->next = mergeSortedLL(a->next, b);
        return a;
    }

    b->next = mergeSortedLL(a, b->next);
    return b;

}

int main() {

    // Node * ll = createLL();
    // display(ll);

    // int x; cin >> x;
    // int pos; cin >> pos;
    // Node * updateLL = insertAtPos(ll, x, pos);  // insert after pos
    // display(updateLL);

    // int pos; cin >> pos;
    // Node* updateLL = deleteNode(ll, pos);
    // display(updateLL);

    // int len = lengthLL(ll);
    // cout << len;

    // int x; cin >> x;
    // int pos = findElement(ll, x);
    // cout << pos << endl;

    // Node* mid = midNode(ll);
    // cout << mid << " " << endl;
    // if (mid) cout << mid->data << endl;

    Node* a = createLL();
    Node* b = createLL();
    Node* ans = mergeSortedLL(a, b);
    display(ans);



}