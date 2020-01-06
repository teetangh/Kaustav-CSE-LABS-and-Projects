module dff1(d,clk,q);
input clk,d;
output q;
reg q;
always @ (posedge clk)
begin
q=d;
end
endmodule
module john_counter(clk,q);
input clk;
output [4:0] q;
wire [4:0] q;
dff1 st0(~q[0],clk,q[4]);
dff1 st1(q[4],clk,q[3]);
dff1 st2(q[3],clk,q[2]);
dff1 st3(q[2],clk,q[1]);
dff1 st4(q[1],clk,q[0]);
endmodule


