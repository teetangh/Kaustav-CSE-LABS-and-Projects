module d(w,s,f);
input [3:0]w;
input [1:0]s;
output f;
reg f;
function mux21;
input [1:0]x;
input s2;
case(s2)
0:mux21=x[0];
1:mux21=x[1];
endcase
endfunction
always@(w|s)
case(s[1])
0:f=mux21(w[1:0],s[0]);
1:f=mux21(w[3:2],s[0]);
endcase
endmodule
