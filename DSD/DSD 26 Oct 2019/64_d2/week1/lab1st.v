module lab1st(x1,x2,x3,f);
input x1,x2,x3;
output f;
and(a,x1,x2);
not(c,x2);
and(b,c,x3);
or(f,a,b);
endmodule
