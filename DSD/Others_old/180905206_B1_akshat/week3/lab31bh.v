module lab31bh(a,b,c,d,f);
input a,b,c,d;
output f;
wire p,q,r,s,g;
assign p = ~(b&b);
assign q = ~(d&d);
assign r = ~(a&p);
assign s = ~(c&q);
assign g = ~(r&s);
assign f = ~(g&g);
endmodule
