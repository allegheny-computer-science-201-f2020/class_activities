// By default, C++ uses static method binding (Java, by default, uses dynamic).
//
// To compile this program, type:
//    g++ staticbind.cpp -o static
//    ./static

#include <iostream>
using namespace std;

class Super {
  private:
      int x;
  public:
      Super(int x) { 
         this->x = x; 
      }
      int get() {
         return x; 
      } 
};

class Sub: public Super {
  private:
     int y;
  public:
     Sub(int x, int y): Super(x) {
        this->y = y;
      }
     int get() {
        return y;
      }
};

int main() {
   Sub   a(10,20);
   Super b = a;
   cout << a.get() << endl; // Which "get"?
   cout << b.get() << endl; // Which "get"?
}  