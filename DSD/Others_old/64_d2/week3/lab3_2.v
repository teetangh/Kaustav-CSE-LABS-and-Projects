module lab3_2(a,b,c,d,e,f,g,h,i,j);
input a,b,c,d;
output e,f,g,h,i,j;
nor(e,d,d);nor(f,b,c);nor(g,b,d);
nor(h,a,c,e);nor(i,f,g,h);nor(j,i,i);
endmodule
