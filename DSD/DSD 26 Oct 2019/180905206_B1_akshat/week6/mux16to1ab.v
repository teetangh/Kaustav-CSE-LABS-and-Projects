module mux8to1(w,s,f);
input [7:0]w;
input [2:0]s;
output f;
reg f;
always @ (w or s)
begin
case(s)
0:f=w[0];
1:f=w[1];
2:f=w[2];
3:f=w[3];
4:f=w[4];
5:f=w[5];
6:f=w[6];
7:f=w[7];
endcase
end
endmodule
module mux21(w,s,f);
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
module mux16to1ab(w,s,f);
input [15:0]w;
input [3:0]s;
output [2:0]f;
mux8to1 st0(w[7:0],s[2:0],f[0]);
mux8to1 st1(w[15:8],s[2:0],f[1]);
mux21 st2(f[1:0],s[3],f[2]);
endmodule

