module mux8to1(w,s,f);
input [7:0]w;
input [2:0]s;
output f;
reg f;
always @ (w or s)
begin
case(s)
0:f=w[0];
1:f=w[1];
2:f=w[2];
3:f=w[3];
4:f=w[4];
5:f=w[5];
6:f=w[6];
7:f=w[7];
endcase
end
endmodule
module bcdtoex(bcd,ex);
input [3:0] bcd;
output [3:0] ex;
wire [7:0] w1,w2,w3,w4;
assign w4 = {1'b0,1'b0,1'b0,1'b1,1'b1,bcd[0],1'b0,1'b0};
assign w3 = {1'b0,1'b0,1'b0,bcd[0],1'b0,~bcd[0],1'b1,bcd[0]};
assign w2 = {1'b0,1'b0,1'b0,~bcd[0],bcd[0],~bcd[0],bcd[0],~bcd[0]};
assign w1 = {1'b0,1'b0,1'b0,~bcd[0],~bcd[0],~bcd[0],~bcd[0],~bcd[0]};
mux8to1 st0(w4,bcd[3:1],ex[3]);
mux8to1 st1(w3,bcd[3:1],ex[2]);
mux8to1 st2(w2,bcd[3:1],ex[1]);
mux8to1 st3(w1,bcd[3:1],ex[0]);
endmodule

