module lab33bh(x1,x2,x3,x4,x5,f);
input x1,x2,x3,x4,x5;
output f;
wire p,q,a,b,g;
assign p = ~x1|x2;
assign g = p&x5;
assign q = ~(x3^x4);
assign a = g&q;
assign b = ~x3&~g&x4;
assign f = a|b;
endmodule
