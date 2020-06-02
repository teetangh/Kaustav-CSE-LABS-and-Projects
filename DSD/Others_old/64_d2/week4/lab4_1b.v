module lab4_1b (x,y,ci,c,s,m,n,o,e);
input x,y,ci;
output c,s,m,n,o,e;
and(m,x,y);
and(n,y,ci);
and(o,ci,x);
or(c,m,n,o);
xor(e,x,y);
xor(s,e,ci);
endmodule
