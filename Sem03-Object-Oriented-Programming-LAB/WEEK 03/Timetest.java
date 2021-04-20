class Time
{
  int hours;
  int minutes;
  int seconds;

  Time(int hours,int minutes,int seconds)
  {
   this.hours=hours;
   this.minutes=minutes;
   this.seconds=seconds;
  }
  
  void display()
  {
   System.out.println("Time in hh:mm:ss is " + hours +" "+ minutes+" " + seconds );
  } 

  Time addtime(Time t1)
  {
   this.hours+=t1.hours;
   this.minutes+=t1.minutes;
   this.seconds+=t1.seconds;
   
   if(this.minutes>60)
     {
     int x=this.minutes/60;
     int y=this.minutes%60;
     this.hours+=x;
     
     this.minutes=y;
     }
     
   if(this.seconds>60)
     {
     int x=this.seconds/60;
     int y=this.seconds%60;
     this.minutes+=x;
     this.seconds=y;
     }
   return this;
  }
  
  Time subtime(Time t1)
  {
   this.hours-=t1.hours;
   //minutes sub
   if(this.minutes-t1.minutes<0)
     {
       this.minutes=this.minutes-t1.minutes+60;
       this.hours--;
     }
   else
     {
       this.minutes=this.minutes-t1.minutes;
     }  
   //seconds sub
   if(this.seconds-t1.seconds<0)
      {
       this.seconds=this.seconds-t1.seconds+60;
       this.minutes--;
     }
   else
     {
       this.seconds=this.seconds-t1.seconds;
     }  
   return this;
  }
}

class Timetest
{
 public static void main(String args[])
 {
  Time t1=new Time(4,5,6);
  Time t2=new Time(1,7,8);
  Time t3;//=new Time(0,0,0);
  Time t4;//=new Time(0,0,0);
  
  t3=t1.addtime(t2);
  t3.display();
  
  t1.subtime(t2);
  
  t4=t1.subtime(t2);
  t4.display();
 }
}

