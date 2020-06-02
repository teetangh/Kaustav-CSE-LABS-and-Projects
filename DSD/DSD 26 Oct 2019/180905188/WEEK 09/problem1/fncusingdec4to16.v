module dec3to8(w,y,en);
	input [2:0]w;
	input en;
	output [7:0]y;
	reg [7:0]y;
	always@(w or en)
	begin
		if(en==0)
		 	y=8'b00000000;
		else
		begin
			case(w)
			3'b000:y=8'b00000001;
			3'b001:y=8'b00000010;
			3'b010:y=8'b00000100;
			3'b011:y=8'b00001000;
			3'b100:y=8'b00010000;
			3'b101:y=8'b00100000;
			3'b110:y=8'b01000000;
			3'b111:y=8'b10000000;
			endcase
		end
	end
endmodule

module dec4to16using3to8(nw,ny,en2);
	input [3:0]nw;
	input en2;
	output [15:0]ny;
	reg [15:0]ny;
	wire i1,i2;
	assign i1=~nw[3]&en2;
	assign i2=nw[3]&en2;
	dec3to8 stage0(nw[2:0],ny[7:0],i1);
	dec3to8 stage1(nw[2:0],ny[15:8],i2);
endmodule

module fncusingdec4to16(x,f,F);
	input [3:0]x;
	output [15:0]f;
	output F;
	dec4to16using3to8 stage0(x[3:0],f[15:0],en3);
	assign F=f[1]|f[3]|f[6]|f[7]|f[9]|f[14]|f[15];
endmodule
