module de2to4_low(w,y,en);
input [1:0] w;
input en;
output [3:0] y;
reg [3:0] y;
always @ (w or en)
begin
if(en==0)
y=15;
else
begin
case(w)
0:y=14;
1:y=13;
2:y=11;
3:y=7;
endcase
end
end
endmodule
module de4to16_low(w,y,en);
input [3:0] w;
input en;
output [15:0] y;
wire [3:0] w1,w2;
de2to4_low st0(w[3:2],w1,en);
assign w2 = {~w1[3],~w1[2],~w1[1],~w1[0]};
de2to4_low st1(w[1:0],y[3:0],w2[0]);
de2to4_low st2(w[1:0],y[7:4],w2[1]);
de2to4_low st3(w[1:0],y[11:8],w2[2]);
de2to4_low st4(w[1:0],y[15:12],w2[3]);
endmodule






