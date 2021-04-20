module lab12bh(a,b,c,d,f,g);
input a,b,c,d;
output f,g;
wire h,i;
assign h = ~(a&b);
assign g = ~(b|c|d);
assign i = h^d;
assign f = i^c;
endmodule
 
