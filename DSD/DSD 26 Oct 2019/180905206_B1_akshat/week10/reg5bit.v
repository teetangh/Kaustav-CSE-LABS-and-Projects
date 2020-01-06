module dff1(d,clk,q);
input d,clk;
output q;
reg q;
always @ (negedge clk)
begin
q<=d;
end
endmodule
module reg5bit(w,clk,q);
input [4:0]w;
input clk;
output [4:0]q;
dff1 s0(w[0],clk,q[0]);
dff1 s1(w[1],clk,q[1]);
dff1 s2(w[2],clk,q[2]);
dff1 s3(w[3],clk,q[3]);
dff1 s4(w[4],clk,q[4]);
endmodule

