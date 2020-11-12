// To compile and run this, type:
//    g++ overload.cpp -o overload
//    ./overload

#include <iostream>
#include <string>
using namespace std;

class Pirate {
  public:
    Pirate(string name) { 
       this->name = name;
    }
    string getName() { 
      return name;
    }
    string operator +(Pirate other) { 
      return other.getName()+name;
    }
  private:
     string name;
};

int main() {
  Pirate x("Fred");
  Pirate y("Mary");
  cout << (x+y) << endl;
  cout << (y+x) << endl;
}
