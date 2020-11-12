// The "Diamond problem": 
//            Person
//           /      \
//          /        \
//     Student     Employee
//          \        /
//           \      /
//         StudentEmployee
//
// Problem: the common instance variable "name" is inherited twice by
// "StudentEmployee".
//
// (See file "diamond2.cpp" for one possible solution.)
//
// To compile this, type:
//      g++ diamond1.cpp -o diamond1
// NOTE: it will compile with errors!

#include <iostream>
#include <string>
using namespace std;

// The "top" of the diamond:
class Person {
   private:
      string name;
      string address;
   public:
      Person(string name) {
         this->name = name;
         address =  "unknown";
      }
      string getName() { 
         return name; 
      }
      string getAddress() { 
         return address; 
      }
      void setAddress(string address) { 
         this->address = address; 
      }
};

// A Student is a person with additional information about class year and GPA:
class Student: public Person {
   private:
      int classyear;
      double gpa;
   public:
      Student(string name, int classyear, double gpa): Person(name) {
        this->classyear = classyear;
        this->gpa = gpa;
      }
      int getClassyear() { 
         return classyear; 
      }
      double getGpa() { 
         return gpa; 
      }
      void setGpa(double gpa) { 
         this->gpa = gpa; 
      }
};

// An Employee is a person with additional information about job title and pay:
class Employee: public Person {
   private:
      string jobtitle;
      double payrate;
   public:
      Employee(string name, string jobtitle, double payrate): Person(name) {
        this->jobtitle = jobtitle;
        this->payrate = payrate;
      }
      string getJobtitle() { return jobtitle; }
      double getPayrate() { return payrate; }
};

// A StudentEmployee is a Student and an Employee, with additional information
// about work study status (multiple inheritance):
class StudentEmployee: public Student, public Employee {
   private:
      bool workstudy;
   public:
      StudentEmployee(string name,int classyear,double gpa,
                      string jobtitle,double payrate,bool workstudy): 
                        Employee(name,jobtitle,payrate), Student(name,classyear,gpa) {
         this->workstudy = workstudy;
      }
      bool getWorkstudy() { 
         return workstudy; 
      }
};

// Test the StudentEmployee class. This fails due to an ambiguity:
//     mult2.cpp:85: error: request for member ‘getName’ is ambiguous
//
// There is only one "getName()" method (in class "Person"), but it
// is inherited by BOTH "Student" and "Employee", so C++ does not
// know which one to use.

int main() {
  StudentEmployee joe("Joe Jones",2017,3.052,"teaching assistant",7.25,true);

  cout << joe.getName() << " graduates in " << joe.getClassyear();
  cout << " with a gpa of " << joe.getGpa() << endl;
  cout << joe.getName() << (joe.getWorkstudy()?" has ":" doesn't have ") 
       << "work study" << endl;
  cout << joe.getName() << " has an hourly pay rate of $" << joe.getPayrate() 
       << endl;

}
