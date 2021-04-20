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
module mux4to1(w,s,f);
input [3:0]w;
input [1:0]s;
output[2:0]f;
reg [2:0]f;
mux2to1 st0(w[1:0],s[0],f[0]);
mux2to1 st1(w[3:2],s[0],f[1]);
mux2to1 st2(f[1:0],s[1],f[2]);
endmodule
