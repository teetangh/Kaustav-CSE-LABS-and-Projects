module lab21a(a,b,c,d,f);
input a,b,c,d;
output f;
not(w,a);
not(x,b);
not(y,c);
not(z,d);
and(p,w,b);
and(q,x,c);
and(r,c,d);
and(s,b,y,z);
or(f,p,q,r,s);
endmodule
