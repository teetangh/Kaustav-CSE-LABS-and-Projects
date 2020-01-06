module mux4to1(w,s,f);
	input [3:0]w;
	input [1:0]s;
	output f;
	reg f;
	always@(w or s)
	begin
		case(s)
		2'b00:f=w[0];
		2'b01:f=w[1];
		2'b10:f=w[2];
		2'b11:f=w[3];
		endcase
	end
endmodule
module test2(en,ns,nf);
	input en;
	input [1:0]ns;
	output [3:0]nf;
	reg	[3:0]nf;
	always@(en or ns)
	begin
	if(en==1)
	begin
		nf=4'b1111;
	end
	else
		begin
		mux4to1 stage0(4'b1110,ns[1:0],nf[0]);
		mux4to1 stage1(4'b1101,ns[1:0],nf[1]);
		mux4to1 stage2(4'b1011,ns[1:0],nf[2]);
		mux4to1 stage3(4'b0111,ns[1:0],nf[3]);
		end
	end
endmodule
