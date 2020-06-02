module lab2_3(x1,x2,x3,x4,a,b,c,d,e,f,g,h,i);
input x1,x2,x3,x4;
output a,b,c,d,e,f,g,h,i;
and(a,x1,x2);
and(d,x3,x4);and(b,a,x3);
and(c,a,x4);
and(e,d,x1);and(f,d,x2);
or(g,b,c);or(h,e,f);
or(i,g,h);


endmodule

