class Complexnumber
{ 
  float real;
  float complex;
  

 Complexnumber(float real,float complex)
 {
   this.real=real;
   this.complex=complex;
 }
 Complexnumber addcomplex(Complexnumber c)
  {
   this.real+=c.real;
   this.complex+=c.complex;
   return this;
  }

 Complexnumber subcomplex(Complexnumber c)
  {
   this.real-=c.real;
   this.complex-=c.complex;
   return this;
  }
 
 void display(Complexnumber c) 
 {
  System.out.println("The value of the complex number is " + c.real +" + i " + c.complex );
 }
}

class Complex
{ 
 public static void main(String args[])
 {
  Complexnumber c1 = new Complexnumber(2,3);
  Complexnumber c2 = new Complexnumber(4,5);
  
  Complexnumber c3;
  Complexnumber c4;

  c3=c1.addcomplex(c2);
  c3.display(c3);
  
  c4=c1.subcomplex(c2);
  c4.display(c4);
 }
}
