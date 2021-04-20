module de4to16(w,en,y);
input [3:0] w;
input en;
output [15:0] y;
reg [15:0] y;
integer i;
always @ (w or en)
begin
y=0;
if(en==0)
y=0;
else
begin
for(i=0;i<16;i=i+1)
begin
if(w==i)
y[i]=1;
end
end
end
endmodule
module prog1(w,f);
input [3:0] w;
output f;
wire [15:0] y;
de4to16 st0(w,1,y);
assign f = y[1]|y[3]|y[6]|y[7]|y[9]|y[14]|y[15];
endmodule 
