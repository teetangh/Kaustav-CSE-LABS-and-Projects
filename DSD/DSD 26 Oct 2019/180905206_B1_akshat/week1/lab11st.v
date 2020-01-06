module lab11st(a,b,c,d,f);
input a,b,c,d;
output f;
and(g,a,b);
or(i,g,c);
not(j,i);
and(l,j,d);
or(m,d,i);
and(f,l,m);
endmodule

