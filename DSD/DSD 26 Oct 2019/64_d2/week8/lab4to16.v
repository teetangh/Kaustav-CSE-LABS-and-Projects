module de3to8(w,y,en);
input [2:0] w;
input en;
output [7:0] y;
reg [7:0] y;
integer i;
always @ (w or en)
begin
y=0;
if(en==0)
y=0;
else
begin
for(i=0;i<8;i=i+1)
begin
if(w==i)
y[i]=1;
end
end
end
endmodule
module lab4to16(w,y,en);
input [3:0] w;
input en;
output [15:0] y;
wire i1,i2;
assign i1 = ~w[3]&en;
assign i2 = w[3]&en;
de3to8 st0(w[2:0],y[7:0],i1);
de3to8 st1(w[2:0],y[15:8],i2);
endmodule


