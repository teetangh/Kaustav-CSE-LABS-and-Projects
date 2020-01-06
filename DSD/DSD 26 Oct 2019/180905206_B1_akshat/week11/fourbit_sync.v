module tff1(T,Clock,Q);
input T,Clock;
output Q;
reg Q;
always @ (posedge Clock)
if(!T)
Q<=Q;
else
Q<=~Q;
endmodule
module fourbit_sync(clk,q);
input clk;
output [3:0]q;
tff1 st0(q[2]&q[1]&q[0],clk,q[3]);
tff1 st1(q[1]&q[0],clk,q[2]);
tff1 st2(q[0],clk,q[1]);
tff1 st3(1,clk,q[0]);
endmodule

