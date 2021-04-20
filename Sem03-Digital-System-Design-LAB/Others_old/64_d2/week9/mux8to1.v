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
module mux8to1(w,s,f);
input [7:0] w;
input [2:0] s;
output f;
wire [7:0] y;
wire [7:0] w1;
de3to8 st0(s,y,1);
assign w1 = {y[7]&w[7],y[6]&w[6],y[5]&w[5],y[4]&w[4],y[3]&w[3],y[2]&w[2],y[1]&w[1],y[0]&w[0]};
assign f = w1[0]|w1[1]|w1[2]|w1[3]|w1[4]|w1[5]|w1[6]|w1[7];
endmodule
