module lab1ex2(a,b,c,d,f,g);
input a,b,c,d;
output f,g;
nand(e,a,b);
xor(x,e,d);
xor(f,x,c);
nor(g,c,b,d);
endmodule
