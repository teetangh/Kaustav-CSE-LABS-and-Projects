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


