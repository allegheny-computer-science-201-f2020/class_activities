class Super {
 public String talk() {
   return "hello";
 }
}

class Sub extends Super {
  public String talk() {
    return "goodbye";
  }
}

class DynamicDemo {
  public static void main (String args []) {
    Super x = new Super();
    Sub y = new Sub();
    f(x); 
    f(y);
  }

  public static void f (Super a) {
   System.out.println(a.talk());
  }
}
