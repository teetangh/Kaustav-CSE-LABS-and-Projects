module mux21(w,s,f);
input [1:0]w;
input s;
output f;
function mux;
input [1:0]x;
input ss;
if(ss==0)
mux=x[0];
else
mux=x[1];
endfunction
assign f = mux(w,s);
endmodule
module mux4to1ab(w,s,f);
input [3:0]w;
input [1:0]s;
output[2:0]f;
reg [2:0]f;
mux21 st0(w[1:0],s[0],f[0]);
mux21 st1(w[3:2],s[0],f[1]);
mux21 st2(f[1:0],s[1],f[2]);
endmodule

