module lab3_3(x1,x2,x3,x4,x5,a,b,c,d,e,f,g,h,i,j,k,l,m,n);
input x1,x2,x3,x4,x5;
output a,b,c,d,e,f,g,h,i,j,k,l,m,n;
not(a,x1);not(b,x3);not(c,x4);
or(d,a,x2);and(e,d,x5);
and(f,b,c);and(g,x3,x4);
and(h,b,x4);
not(i,e);and(j,e,f);and(k,e,g);
and(l,i,h);or(m,j,k);or(n,m,l);
endmodule
