// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

struct Node {
    string key; // object
    int val;
    Node* next;
};

class Hashmap {
    Node * *table;
    int sze;
    int capacity = 0;

    void insertIntoList(int idx, Node* tmp) {
        Node*& head = table[idx];
        if (head == NULL) {
            head = tmp;
        }
        else {
            tmp->next = head;
            head = tmp;
        }
    }

    double loadFactor() {
        return (double)sze / capacity;
    }

    void hashFunction(const string& s) {
        int hashCode = 0;
        int mul = 31;       // he told me to take prime...research
        const int MOD = capacity;

        for (int i = 0; i < s.size(); ++i) {
            hashCode = (mul * hashCode) % MOD;
            hashCode = (hashCode + s[i] % MOD) % MOD;
            mul = (mul * 31) % MOD;
        }
        return hashCode;
    }

    void rehash() {
        Node* oldTable = table;
        int oldCapacity = capacity;
        capacity = 2 * oldCapacity;
        table = new Node*[capacity];
        sze = 0;    // insert function increases size

        for(int i = 0; i < oldCapacity; ++i){
            Node* head = table[idx];
            while(head != NULL){
                // insert into newtable
                Node* nextItem = head->next;
                head->next = NULL;
                insert(head);
                head = nextItem;
            }
        }
        delete [] oldTable;
    }

    void insert(Node* tmp){
         int hashCode = hashFunction(tmp->key);
        int idx = hashCode % capacity;
        insertIntoList(idx, tmp);
        ++sze;

        if (loadFactor() > 0.7) {
            rehash();
        }
    }

public:
    Hashmap() {
        capacity = 7;
        sze = 0;
        table = new Node*[capacity];
    }

    void insert(const string& s, const int& val) {
        Node* tmp = new Node();
        tmp->key = s;
        tmp->val = val;
        tmp->next = NULL;
        insert(tmp);       
    }

    int at(const string& s){
        // returns the val
        int idx = hashFunction(s) % capacity;
        Node* head = table[idx];

        // search s in the list
        while(head){
            if (head->key == s){
                return head->val;
            }
            head = head->next;
        }

        return -1;
    }

    bool empty(){
        return sze == 0;

    }

    void remove(const string& s){
        // delete from list
        int idx = hashFunction(s) % capacity;
        Node* head = table[idx];

        // delete element with s from the list
    }

}


int main() {

}