#include <iostream>

 // #1 EXAMPLE OF A MACRO
#define SQUARE(a) ((a)*(a)) // NOTE the parenthesis

// #2 Template example(s), the types used must support the operators used on them
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T max(T a, T b) {
    return (a > b) ? a : b;
} 

// Example #3
template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b;
}

// Example # 4, using the template on objects, need to overload operators here. S
template <typename Tm>
Tm min(Tm a, Tm b) {
    return (a < b) ? a : b;
}

/////////////////////////////////////////   T E M P L A T E   F U N C T I O N S ////////////////////////////////////////////////

struct Person {
    std::string name;
    int age;
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
};

// Overloading the insertion operator to make sure 'Person' can get printed. 
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name;
    return os;
}

// A template function to swap any 2 types
template <typename S>
void my_swap(S &a, S &b) {
    S temp = a;
    a = b;
    b = temp;
}

////////////////////////////////////// T E M P L A T E    C L A S S //////////////////////////////////////////////////////

/** @brief : Template classes are always defined in headers, DO NOT define them in cpp files*/ 

template <typename T>
class Item {
private:
    std::string name_;
    T value_;
public:
    Item(std::string name, T value) : name_(name), value_(value) {}
    std::string get_name() const {return name_;}
    T get_value() const {return value_;}
};

////////////////////////////// A R R A Y   T E M P L A T E  C L A S S ///////////////////////////

template <typename A, int N>
class Array {
    int size{N};
    ADJ_MAXERROR values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<A, N> &arr) {
        os << "[";
        for (const auto &val : arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }
public:
    Array{} = default;            // Constructor
    Array(A init_val) {           // Constructor that initializes the values
        for(auto &item : values)
            item = init_val;
    }
    void fill(A val) {            // Filling up the values
        for(auto &item: values)
            item = val;
    }
    int get_size() const {        // Getting size of array 
        return size;
    }
    int &operator[](int index) {
        return values[index];
    } 
};

////////////////////////////////////////// M A I N //////////////////////////////////////////
int main(int argc, char const *argv[])
{
    // Example of implementation #2
    double c, d;
    std::cout << max<double>(c, d); 

    // Example of implementation #3
    func <int,double>(10, 20.02); //If we dont declare those types, they are interpreted by the compiler

    // Example of implementation #4
    Person p1("Jibran", 24);
    Person p2("Omar", 15);
    Person p3 = min(p2, p1);  // Can use the templated function as we have defined the operator

    return 0;
}
