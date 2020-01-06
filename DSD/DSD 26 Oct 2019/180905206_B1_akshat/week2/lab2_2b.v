module lab2_2b(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s);
input a,b,c,d;
output e,f,g,h,i,j,k,l,m,n,o,p,q,r,s;
not(e,a);
not(f,d);
not(g,b);
not(h,c);
or(j,e,b);or(i,f,e);or(k,i,c);or(m,d,c);
or(l,m,g);or(o,h,d);or(n,j,h);or(p,o,a);
and(q,p,n);
and(r,k,l);
and(s,r,q);
endmodule

