module lab22abh(b,c,d,f);
input b,c,d;
output f;
wire p,q;
assign p = b|c;
assign q = ~b|d;
assign f = p&q;
endmodule
