module lab1(x1,x2,x3,f);
input x1,x2,x3;
output f;
and(g,x1,x2);
not(i,x2);
and(h,i,x3);
or(f,g,h);
endmodule

