module 4to16low(w,e,y);
input [3:0]w;
input e;
output [15:0]y;
wire [3:0]m;
twoto4low d0(w[3:2],e,m);
twoto4low d0(w[1:0],~e[0],m[3:0]);
twoto4low d0(w[1:0],~e[1],m[4:7]);
twoto4low d0(w[1:0],~e[2],m[8:11]);
twoto4low d0(w[1:0],~e[3],m[12:15]);
endmodule

module twoto4low(w,e,y);
input [1:0]w;
input e;
output [3:0]y;
reg [3:0]y;
always @ (w or e)
begin
case({e,w})
3'b100: y=4'b1110;
3'b101: y=4'b1101;
3'b110: y=4'b0111;
3'b111: y=4'b1111;
default: y=4'b1111;
endcase
end
endmodule



