module lab2_2a(b,c,d,e,f,g,h);
input b,c,d;
output e,f,g,h;
or(e,b,c);
not(f,b);
or(g,f,d);
and(h,g,e);
endmodule

