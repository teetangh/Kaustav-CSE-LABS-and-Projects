module de2to4(w,y,en);
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
if(w==0)
y=1;
else if(w==1)
y=2;
else if(w==2)
y=4;
else
y=8;
end
end
endmodule
module lab8q1(w,y,en);
input [2:0] w;
input en;
output [7:0] y;
wire i1,i2;
assign i1=~w[2]&en;
assign i2=w[2]&en;
de2to4 st0(w[1:0],y[3:0],i1);
de2to4 st1(w[1:0],y[7:4],i2);
endmodule
