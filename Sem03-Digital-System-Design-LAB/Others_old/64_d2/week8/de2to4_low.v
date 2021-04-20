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
