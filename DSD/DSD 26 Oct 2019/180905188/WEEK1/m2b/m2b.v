module m2b(f,g,a,b,c,d);
input a,b,c,d;
output f,g;

assign f = ((~(a&b)^c^d));
assign g = (~(b|c|d));

endmodule
















