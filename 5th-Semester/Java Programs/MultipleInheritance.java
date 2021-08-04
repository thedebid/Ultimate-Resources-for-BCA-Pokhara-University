/* In Multiple inheritance, one class can have more than one superclass 
and inherit features from all its parent classes.
But java does not support multiple class inheritance.
To overcome this problem we use interfaces to achieve multiple class inheritance.
*/

import java.util.Scanner;
 class A{
         int a,b;
         Scanner obj;
         void get(){
             obj = new Scanner(System.in);
             System.out.println("Enter two numbers: ");
             a = obj.nextInt();
             b = obj.nextInt();
         }
     }
 interface B{
     void sum();
 }
 class C extends A, implements B {
     int sum;
     void sum()
     {
         sum = a+b;
     }
     void display()
     {
         System.out.print("Sum of two numbers: "+sum);
     }
 }
 public class multipleInheritance {
     public static void main(String args[]){
         C ob = new C();
        ob.get();
        ob.sum();
        ob.display();
     }
 }