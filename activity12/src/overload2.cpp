/**
 * Janyl Jumadinova
 *
 * TODO: Describe what is happening in this program.
 *       Which operators are overloaded? 
 *       What happens to precedence and associativity of these operators?
 *
 * To compile and run:
 *     g++ overload2.cpp -o overload2
 *     ./overload2
 */

#include <iostream>
#include <string>
using namespace std;

class Pirate {
  public:
     // Constructor: create a named Pirate
     Pirate(string name) { this->name = name;}

     // Accessor method:
     string getName() { return name;}

     // + operator. 
     // Create a new Pirate whose name is the concatenation of 
     // this Pirate's name and the other Pirate's name with a "+" in between.
     // Surround all with parentheses.
     Pirate operator +(Pirate other) { 
        return Pirate("(" + name + " + " + other.getName() + ")");
     }

     // /= operator.
     // Create a new Pirate whose name is the concatenation of 
     // this Pirate's name and the other Pirate's name with a "*" in between.
     // Surround all with brackets.
     Pirate operator /=(Pirate other) { 
        return Pirate("[" + name + " * " + other.getName() + "]");
     }

  private:
     string name;
};

int main() {
  Pirate x("Hugo");
  Pirate y("Gwendolyn");
  Pirate z("Severus");

  Pirate a = x /= y /= z; // Demonstrate right associativity of /=: 
  Pirate b = (x /= y) /= z;
  Pirate c = x /= y + z;  // Demonstrate that + has precedence over /=:
  Pirate d = (x /= y) + z;
  Pirate e = x + y + z;  // Demonstrate left associativity of +:
  Pirate f = x + (y + z);  // Demonstrate left associativity of +:

  cout << "x = " << x.getName() << endl;
  cout << "y = " << y.getName() << endl;
  cout << "z = " << z.getName() << endl;

  cout << "x /= y /= z = " << a.getName() << endl;
  cout << "(x /= y) /= z = " << b.getName() << endl;
  cout << "x /= y + z = " << c.getName() << endl;
  cout << "(x /= y) + z = " << d.getName() << endl;
  cout << "x + y + z = " << e.getName() << endl;
  cout << "x + (y + z) = " << f.getName() << endl;
}
