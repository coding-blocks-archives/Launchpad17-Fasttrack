// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Fruit{
private:    // default
    char * origin;  // dynamic
    char color[10];

public:
    Fruit(const char c[], const char o[]){
        strcpy(color, c);

        // allocate space for origin
        int len = strlen(o);
        origin = new char[len + 1]; // Null char
        strcpy(origin, o);
    }

    Fruit(const Fruit& tmp){
        strcpy(color, tmp.color);

        int len = strlen(tmp.origin);
        origin = new char[len + 1];
        strcpy(origin, tmp.origin);
    }

    void display(){
        cout << color << " " << origin << endl;
    }

    void updateOrigin(const char* o){
        delete origin;
        int len = strlen(o);
        origin = new char[len + 1];
        strcpy(origin, o);
    }

    ~Fruit(){
        // when obj goes out of the scope (lifetime)
        cout << "Dtor called\n";
        delete [] origin;
    }

};

void Foo(){
    Fruit mango("Red", "India");
    mango.display();
    cout << "happy new Year\n";
    // mango.cleanUp();
}
int main(){
    // Fruit mango("yellow", "India");
    // Fruit mango2(mango);
    // strcpy(mango.origin, "China");


    // mango.updateOrigin("china");
    // mango.display();
    // mango2.display();
    
    Foo();

     mango2 = mango;
    Foo();
    Foo();
    char c ;
    cin >> c;

}