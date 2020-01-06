module lab3_1(a,b,c,d,j);
input a,b,c,d;
output j;
nand(e,b,b);nand(f,d,d);nand(g,e,a);
nand(h,f,c);nand(i,g,h);
nand(j,i,i);
endmodule
