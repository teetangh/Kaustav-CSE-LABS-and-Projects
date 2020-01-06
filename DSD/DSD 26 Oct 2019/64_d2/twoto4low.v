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



