class Parent {
   public void method() {
      System.out.println("This is parent class method.");
   }
}

class Child extends Parent {
   public void method() {
      System.out.println("This is child class method.");
   }
}

public class Poly {
   public static void main(String args[]) {

      Parent parent1 = new Parent();
      Parent parent2 = new Child();

      // TODO: This will invoke method() of which class?
      parent1.method();
      // TODO: This will invoke method() of which class?
      parent2.method();
   }
}
