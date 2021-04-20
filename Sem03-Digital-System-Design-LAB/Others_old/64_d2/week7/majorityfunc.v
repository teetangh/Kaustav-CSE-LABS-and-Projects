module mux2to1(w,s,f);
input [1:0]w;
input s;
output f;
reg f;
always @ (w or s)
begin
if(s==0)
f=w[0];
else
f=w[1];
end
endmodule
module majorityfunc(x,f);
input [3:1] x;
output f;
wire [1:0] w;
assign w[0] = x[2] & x[3];
assign w[1] = x[2] | x[3];
mux2to1 st0(w,x[1],f);
endmodule
