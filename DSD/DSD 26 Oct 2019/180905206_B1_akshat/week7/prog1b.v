module mux4to1(w,s,f);
input [3:0]w;
input [1:0]s;
output f;
assign f = s[0]?(s[1]?w[3]:w[1]):(s[1]?w[2]:w[0]);
endmodule
module prog1b(x,f);
input [3:0] x;
output f;
wire [3:0] w;
wire [1:0] s;
assign w[0] = x[1]|~x[0];
assign w[1] = x[0];
assign w[2] = 0;
assign w[3] = 0;
assign s[0]=x[2];
assign s[1]=x[3];
mux4to1 st0(w,s,f);
endmodule
