module tff1(T,Clock,Q);
input T,Clock;
output Q;
reg Q;
always @ (negedge Clock)
if(!T)
Q<=Q;
else
Q<=~Q;
endmodule
module fourbit(clk,Q);
input clk;
output [3:0]Q;
tff1 st0(1,clk,Q[0]);
tff1 st1(1,Q[0],Q[1]);
tff1 st2(1,Q[1],Q[2]);
tff1 st3(1,Q[2],Q[3]);
endmodule
