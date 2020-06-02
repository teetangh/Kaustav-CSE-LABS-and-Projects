module de2to4_high(w,y,en);
input [1:0] w;
input en;
output [3:0] y;
reg [3:0] y;
always @ (w or en)
begin
if(en==0)
y=0;
else
begin
case(w)
0:y=1;
1:y=2;
2:y=4;
3:y=8;
endcase
end
end
endmodule
module de4to16_high(w,y,en);
input [3:0] w;
input en;
output [15:0] y;
wire [3:0] w1;
de2to4_high st0(w[3:2],w1,en);
de2to4_high st1(w[1:0],y[3:0],w1[0]);
de2to4_high st2(w[1:0],y[7:4],w1[1]);
de2to4_high st3(w[1:0],y[11:8],w1[2]);
de2to4_high st4(w[1:0],y[15:12],w1[3]);
endmodule
module prog2(w,f,g,h);
input [3:0] w;
output f,g,h;
wire [15:0] y;
de4to16_high st0(w,y,1);
assign f = y[3]|y[6]|y[7]|y[10]|y[11]|y[14];
assign g = y[2]|y[3]|y[10]|y[14];
assign h = y[0]|y[1]|y[3]|y[7]|y[14]|y[15];
endmodule
