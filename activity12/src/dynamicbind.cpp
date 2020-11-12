// By default, C++ uses static method binding (Java, by default, uses dynamic).
// Here is one way to do dynamic binding in C++.
//
// To compile this program, type:
//    g++ dynamicbind.cpp -o dynamic
//    ./dynamic

#include <iostream>
using namespace std;

class Super {
  private:
      int x;
  public:
      Super(int x) { this->x = x; }
      virtual int get() {
         return x; 
      }  // NOTE the "virtual"
};

class Sub: public Super {
  private:
     int y;
  public:
     Sub(int x, int y): Super(x) {this->y = y;}
     int get() {
        return y;
      }
};

int main() {
   Sub   a(10,20);
   Super *b = &a; // NOTE: pointer variable
   cout << a.get() << endl; // Which "get"?
   cout << b->get() << endl; // Which "get"?
}  

