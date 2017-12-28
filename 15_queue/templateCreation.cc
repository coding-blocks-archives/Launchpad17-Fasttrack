
template <typename T>
class Pair {
    T n1;
    T n2;
public: Pair() {
        // n1.assign(1); // n1.assign(0) --> n1.operator=(0)
        n1 = 0;
        n2 = 3.0;
    }
};

class Elephant{
    int weight;
    int tailLength;
    int teethLength;
public:
    // void operator=(int d){
    void operator=(int d){
        weight = d;
        tailLength = d;
        teethLength = d;
    }

    void operator=(double d){
        weight = d;
        tailLength = d;
        teethLength = d;
    }
};


int main() {
    Pair<Elephant> p; // pair of integers

    // Elephant E;
    // E.assign(3);
}