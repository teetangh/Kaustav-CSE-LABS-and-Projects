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
module majoronly_two(x,f);
input [3:1] x;
output f;
wire [1:0] a,b,w;
assign a[0] = 0;
assign a[1] = x[3];
mux2to1 st0(a,x[2],w[0]);
assign b[0] = x[3];
assign b[1] = 1;
mux2to1 st1(b,x[2],w[1]);
mux2to1 st2(w,x[1],f);
endmodule
