module lab1ex2st(a,b,c,d,f,g);
input a,b,c,d;
output f,g;
wire e,x;
assign e=~(a&b);
assign x=e^d;
assign f=x^c;
assign g=~(a|b|c);
endmodule
