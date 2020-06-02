module m2a(f,g,a,b,c,d);
input a,b,c,d;
output f,g;

nand(t1,a,b);
xor(t2,t1,d);
xor(f,t2,c);

nor(g,b,c,d);

endmodule
