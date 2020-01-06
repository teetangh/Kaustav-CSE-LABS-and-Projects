module lab11bh(a,b,c,d,f);
input a,b,c,d;
output f;
wire g,l,m,i;
assign g = a&b;
assign i = g|c;
assign l = ~i&d;
assign m = d|i;
assign f = l&m;
endmodule

