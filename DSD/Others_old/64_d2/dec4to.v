module dec4to(w,e,y);
input [3:0]w;
input e;
output [15:0]y;

wire e0,e1;
assign e0=(~w[3])&e;
assign e1=w[3]&e;
dec3to8t stg1(w[2:0],e0,y[7:0]);
dec3to8t stg2(w[2:0],e1,y[15:8]);
endmodule


module dec3to8t(w,e,y);
input [2:0]w;
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

