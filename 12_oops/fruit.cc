// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Fruit{
private:
    char color[15];
    char origin[15];

public:
    //ctor
    Fruit(const char c[], char o[]){
        // color = c;   // array!!!
        // strcpy(o, "Pakistan");
        strcpy(color, c);
        strcpy(origin, o);
    }

    void display(){
        cout << "My color is " << color << endl;
        cout << "My origin is " << origin << endl;
    }

    void updateColor(const char* newColor){
        // color = newColor;
        // newColor = xxxx

        strcpy(color, newColor);
    }
};

int main(){
    char country[] = "Bharat";

    Fruit mango("Yellow", "iran");
    Fruit apple("Red", "Czechoslvokia");


    Fruit mango2(mango);
    mango2.updateColor("red");

    mango.display();
    mango2.display();


    // strcpy(mango.origin, "China");
    // mango.display();
    // apple.display();


    
}