module dec3to8(w,f,en);
	input [2:0]w;
	input en;
	output [7:0]f;
	reg [7:0]f;
	always@(w or en)
	begin
		if(en==0)
		 	f=8'b00000000;
		else
		begin
			case(w)
			3'b000:f=8'b00000001;
			3'b001:f=8'b00000010;
			3'b010:f=8'b00000100;
			3'b011:f=8'b00001000;
			3'b100:f=8'b00010000;
			3'b101:f=8'b00100000;
			3'b110:f=8'b01000000;
			3'b111:f=8'b10000000;
			endcase
		end
	end
endmodule

module mux8to1usingdec3to8(ns,nw,nf,F,en2);
	input en2;
	input [2:0]ns;
	input [7:0]nw;
	output [7:0]nf;
	output F;
	wire [7:0]k;
	dec3to8 stage0(ns[2:0],nf[7:0],en2);
	assign k[0]=nw[0]&nf[0];
	assign k[1]=nw[1]&nf[1];
	assign k[2]=nw[2]&nf[2];
	assign k[3]=nw[3]&nf[3];
	assign k[4]=nw[4]&nf[4];
	assign k[5]=nw[5]&nf[5];
	assign k[6]=nw[6]&nf[6];
	assign k[7]=nw[7]&nf[7];
	assign F=k[0]|k[1]|k[2]|k[3]|k[4]|k[5]|k[6]|k[7];
endmodule
	
