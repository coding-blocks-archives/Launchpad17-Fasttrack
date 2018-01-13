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
    int capacity;

    void insertIntoList(int idx, Node* tmp) {
        Node*& head = table[idx];   // reference...
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

    int hashFunction(const string& s) {
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
        Node** oldTable = table;
        int oldCapacity = capacity;
        capacity = 2 * oldCapacity;
        table = new Node*[capacity](); // WARNING! MUST be initialised
        sze = 0;    // insert function increases size

        for (int i = 0; i < oldCapacity; ++i) {
            Node* head = oldTable[i];
            while (head != NULL) {
                // insert into newtable
                Node* nextItem = head->next;
                head->next = NULL;
                insert(head);
                head = nextItem;
            }
        }
        delete [] oldTable;
    }

    void insert(Node* tmp) {
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
        cout << "Welcome, Creating hashmap...\n";
        capacity = 7;
        sze = 0;
        table = new Node*[capacity](); // initialise all ptrs to NULL. WARNING!!!
    }

    void insert(const string& s, const int& val) {
        Node* tmp = new Node();
        tmp->key = s;
        tmp->val = val;
        tmp->next = NULL;
        insert(tmp);
    }

    int at(const string& s) {
        // returns the val
        int idx = hashFunction(s) % capacity;
        Node* head = table[idx];

        // search s in the list
        while (head) {
            if (head->key == s) {
                return head->val;
            }
            head = head->next;
        }

        return -1;
    }

    bool empty() {
        return sze == 0;

    }

    void remove(const string& s) {
        // delete from list
        int idx = hashFunction(s) % capacity;
        Node* head = table[idx];

        // delete element with s from the list
        Node* cur = head;
        Node* pre = NULL;
        while (cur) {
            if (cur->key == s) {
                if (cur == head) {
                    table[idx] = cur->next;
                    delete cur;
                } else {
                    pre->next = cur->next;
                    delete cur;
                }
                --sze;
            }
            pre = cur;
            cur = cur->next;
        }
    }

    ~Hashmap() {
        for (int i = 0; i < capacity; ++i) {
            Node* head = table[i];
            while (head) {
                Node* tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        delete [] table;
        cout << "Bye! Dtor called\n";
    }

    void printHashMap(){
        for(int i = 0; i < capacity; ++i){
            Node* head = table[i];
            cout << i << "\t:\t";
            while(head){
                cout << head->key << "-->";
                head = head->next;
            }
            cout << endl;
        }
    }

};

int main() {
    Hashmap h;
    h.insert("Tina", 123);
    h.insert("Meena", 234);
    h.insert("Meena1", 234);
    h.insert("Meena2", 234);
    h.insert("Meena3", 234);
    h.insert("Meena4", 234);
    h.insert("Meena5", 234);
    h.insert("Meena6", 234);
    h.insert("Meena7", 234);
    h.insert("Meena8", 234);
    h.insert("Meena9", 234);
    h.insert("Meena10", 234);
    // h.remove("Tina");
    // h.printHashMap();
    h.printHashMap();
    // h.printHashMap();
    // h.printHashMap();
    // h.printHashMap();
    // h.printHashMap();

    cout << "Tina " << h.at("Tina") << endl;
    cout << "Kareena " << h.at("Kareena") << endl;
    cout << "Meena " << h.at("Meena") << endl;

}