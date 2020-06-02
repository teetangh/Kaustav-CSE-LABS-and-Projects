package p1;

class Maximum
{
  int max(int a,int b,int c)
  {
  	if(a>b && a>c)return a;
  	else if(b>a && b>c)return b;
  	else return c;  	
  }
  float max(float a,float b,float c)
  {
  	if(a>b && a>c)return a;
  	else if(b>a && b>c)return b;
  	else return c;  	
  }
  double max(double arr[])
  {
    double temp = arr[0];
    for (int i =0;i<arr.length ;i++ )
    {
     	if(arr[i]>temp)
     	{
     	  arr[i]= arr[i]+temp;
     	  temp	= arr[i]-temp;
     	  arr[i]= arr[i]-temp;
     	}
    }
    return temp;
  }

  double max(double arr[][])
  {
    double temp = arr[0][0];
    for (int i =0;i<arr.length ;i++ )
    {
     for (int j=0;j<arr[i].length ;j++)
      {
     	if(arr[i][j]>temp)
     	{
     	  arr[i][j]= arr[i][j]+temp;
     	  temp	= arr[i][j]-temp;
     	  arr[i][j]= arr[i][j]-temp;
     	}	
      }	
    }
    return temp;
  }

}
