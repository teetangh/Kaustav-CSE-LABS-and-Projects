module mux41(w,s,f);
input [3:0]w;
input [1:0]s;
output f;
assign f = s[0]?(s[1]?w[3]:w[1]):(s[1]?w[2]:w[0]);
endmodule
module mux16to1(w,s,f);
input [15:0]w;
input [3:0]s;
output [4:0]f;
mux41 st0(w[3:0],s[1:0],f[0]);
mux41 st1(w[7:4],s[1:0],f[1]);
mux41 st2(w[11:8],s[1:0],f[2]);
mux41 st3(w[15:12],s[1:0],f[3]);
mux41 st4(f[3:0],s[3:2],f[4]);
endmodule
