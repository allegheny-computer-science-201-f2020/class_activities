/**
 * Janyl Jumadinova
 *
 * TODO: Describe what is happening in this program.
 *       What is being overloaded and how?
 *
 * To compile and run:
 *     g++ overload1.cpp -o overload1
 *     ./overload1
 */

#include <iostream>
#include <string>
using namespace std;

class Pirate {
  public:
    // Constructor: create a named Pirate
    Pirate(string name) { 
      this->name = name;
    }

    // Accessor method:
    string getName() { return name;}

    // + operator. 
    // Create a new Pirate whose name is the concatenation of 
    // the other Pirate's name and this Pirate's name.
    Pirate operator +(Pirate other) { 
      return Pirate(other.getName()+name);
    }

  private:
    string name;
};

int main() {
  Pirate x("Fred");
  Pirate y("Mary");

  // Use the overloaded "+" operator to create two new Pirates:
  Pirate a = x+y; // Alternate notation: Pirate a = x.operator+(y);
  Pirate b = y+x; // Alternate notation: Pirate b = y.operator+(x);

  cout << "First new Pirate: " + a.getName() << endl;
  cout << "Second new Pirate: " + b.getName() << endl;
}
