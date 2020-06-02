module de2to4(w,y,en);
input [1:0] w;
input en;
output [3:0] y;
reg [3:0] y;
always @ (negedge en)
begin
case(w)
0:y=1;
1:y=2;
2:y=4;
3:y=8;
endcase
end
endmodule
module ring_counter(clk,q);
input clk;
output [3:0] q;
wire [1:0] p;
bit2count1 st0(~p[0],clk,p[0]);
bit2count1 st1(p[0]^p[1],clk,p[1]);
de2to4 st2(p,q,clk);
endmodule
