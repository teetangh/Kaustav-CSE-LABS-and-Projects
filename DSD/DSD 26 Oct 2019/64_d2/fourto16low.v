module fourto16low(w,e,y);
input [3:0]w;
input e;
output [15:0]y;
wire [3:0]m;
twoto4low d0(w[3:2],e,m);
twoto4low d1(w[1:0],~m[0],y[3:0]);
twoto4low d2(w[1:0],~m[1],y[7:4]);
twoto4low d3(w[1:0],~m[2],y[11:8]);
twoto4low d4(w[1:0],~m[3],y[15:12]);
endmodule

module twoto4low(w,e,y);
input [1:0]w;
input e;
output [3:0]y;
reg [3:0]y;
always @ (w or e)
begin
case({e,w})
3'b100: y=4'b1110;
3'b101: y=4'b1101;
3'b110: y=4'b0111;
3'b111: y=4'b1111;
default: y=4'b1111;
endcase
end
endmodule
