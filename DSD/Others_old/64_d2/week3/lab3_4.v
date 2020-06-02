module lab3_4(a,c,d,e,f,g,h,i);
input a,d,c;
output e,f,g,h,i;
nor(e,d,d);
nor(f,e,a);
nor(g,c,e);
nor(h,f,g);
nor(i,h,h);
endmodule
