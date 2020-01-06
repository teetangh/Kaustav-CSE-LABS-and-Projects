module lab2_1b(b,c,d,e,f,g,h,i,j,k,l,m);
input b,c,d;
output e,f,g,h,i,j,k,l,m;
not(e,b);
not(f,c);
not(g,d);
and(h,e,d);
and(i,e,c);
and(j,f,g);
and(l,j,b);
or(k,h,i);
or(m,k,l);
endmodule

