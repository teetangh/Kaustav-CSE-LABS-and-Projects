module dec3to8(w,e,y);
input [3:0]w;
input e;
output [7:0]y;
reg [7:0]y;
integer k;
always @ (w or e)
begin
for(k=0;k<=7;k=k+1)
begin
if(w==k && e==1)
   y[k]=1'b1;
else
   y[k]=1'b0;
end
end
endmodule    
