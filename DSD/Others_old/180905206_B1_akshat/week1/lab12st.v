module lab12st(a,b,c,d,f,g);
input a,b,c,d;
output f,g;
nand(h,a,b);
nor(g,c,d,b);
xor(i,d,h);
xor(f,i,c);
endmodule

