module pencoder16to4(w,y,z);
input [15:0] w;
output [3:0] y;
output z;
reg [3:0] y;
reg z;
integer k;
always @ (w)
begin
if(w==0)
begin
z=0;
y=0;
end
else
begin
for(k=0;k<16;k=k+1)
if(w[k]==1)
y=k;
z=1;
end
end
endmodule
