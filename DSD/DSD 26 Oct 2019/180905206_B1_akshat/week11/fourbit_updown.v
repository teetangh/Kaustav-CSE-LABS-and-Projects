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
module fourbit_updown(x,clk,q);
input x,clk;
output [3:0]q;
always @(x)
begin
if(x==1)
q=15;
end
tff1 st0(~x&q[2]&q[1]&q[0],clk,q[3]);
tff1 st1(~x&q[1]&q[0],clk,q[2]);
tff1 st2(~x&q[0],clk,q[1]);
tff1 st3(~x&1,clk,q[0]);
endmodule

