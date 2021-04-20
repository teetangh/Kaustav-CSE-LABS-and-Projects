module lab21b(b,c,d,f);
input b,c,d;
output f;
wire p,q,r;
assign p = b&(~c)&(~d);
assign q = ~b&c;
assign r = ~b&d;
assign f = p|q|r;
endmodule
