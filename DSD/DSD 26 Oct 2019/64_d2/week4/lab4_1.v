module lab4_1 (x,y,c,s);
 input x,y;
 output c,s;
and(c,x,y);
xor(s,x,y);
endmodule
