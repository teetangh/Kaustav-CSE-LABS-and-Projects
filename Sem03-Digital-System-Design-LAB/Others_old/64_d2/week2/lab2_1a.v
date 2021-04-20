module lab2_1a(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p);
input a,b,c,d;
output e,f,g,h,i,j,k,l,m,n,o,p;
not(e,a);
not(f,b);not(k,c);
and(g,e,b);
and(i,f,c);
and(j,c,d);
not(l,d);and(m,k,l);and(n,m,b);
or(h,i,g);
or(o,n,j);
or(p,h,o);
endmodule

