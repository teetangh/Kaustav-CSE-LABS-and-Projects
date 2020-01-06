import java.util.*;
interface Stack 
{
	void  push (int ele) throws StackOverflow;
	void  pop() throws StackUnderflow;
}
class StackOverflow extends Exception
{
	StackOverflow(String msg)
		{
			super(msg);
		}
}

class StackUnderflow extends Exception
{
	StackUnderflow(String msg)
	  {
	  	super(msg);
	  }
}	

class FixedStack implements Stack
{
	int a[];
	int top;
 	FixedStack(int size)
 		{
 			a=new int[size];
 			top=-1;
 		}
 
 	public void push(int ele)throws StackOverflow
 	
 		{
 		              if(top+1==a.length)
 		                 {
 		                    throw new StackOverflow("Overflow");
 		                    
 		                 }
 					top++;
 					a[top]=ele;
 		}
 				
 	public void pop()throws StackUnderflow
 	{
 		if (top==-1)
 		{
 			throw new StackUnderflow("underflow");
 		
 		}
 		System.out.println("popped element"+a[top]);
 		top--;	   		
 	}	
}
class StackDemo
{
	public static void main(String args[])
	{
		int n,e,q;	
		System.out.println("Enter Size of Stack");
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		FixedStack s1=new FixedStack(n);
		try
		{
			System.out.println("enter the element:");
			e=sc.nextInt();
			s1.push(e);
			System.out.println("enter the element:");
			e=sc.nextInt();
			s1.push(e);
			s1.pop();
			s1.pop();
			s1.pop();
		}
		catch(StackOverflow o)
		{System.out.println(o);}
		catch(StackUnderflow f)
		{System.out.println(f);}
	} 					
}				
					
	
	
