module dec2to4(w,y,en);
input [1:0]w;
input en;
output [3:0]y;
reg [3:0]y;
always@(w or en)
begin
	if(en==0)
	y=4'b0000;
	else
	begin
		case(w)
		2'b00: y=4'b0001;
		2'b01: y=4'b0010;
		2'b10: y=4'b0100;
		2'b11: y=4'b1000;
		endcase
	end
end
endmodule

module dec3to8using2to4(nw,ny,en2);
input [2:0]nw;
input en2;
output [7:0]ny;
reg [7:0]ny;
wire i1,i2;
assign i1=~nw[2]&en2;
assign i2=nw[2]&en2;
dec2to4 stage0(nw[1:0],ny[3:0],i1);
dec2to4 stage1(nw[1:0],ny[7:4],i2);
endmodule

module threeinputmajorityfunctionusingdec2to4(x,f,F,en3);
	input [2:0]x;
	input en3;
	output [7:0]f;
	output F;
	dec3to8using2to4 stage0(x[2:0],f[7:0],en3);
	assign F=f[3]|f[5]|f[6]|f[7];
endmodule
