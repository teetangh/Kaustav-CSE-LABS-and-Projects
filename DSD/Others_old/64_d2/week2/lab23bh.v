module lab23bh(x1,x2,x3,x4,f);
input x1,x2,x3,x4;
output f;
wire p,q,r,s;
assign p = x2&x3&x4;
assign q = x1&x3&x4;
assign r = x1&x2&x4;
assign s = x1&x2&x3;
assign f = p|q|r|s;
endmodule
