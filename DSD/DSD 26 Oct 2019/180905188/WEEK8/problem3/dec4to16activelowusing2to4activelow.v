module dec2to4(w,y,en);
input [1:0]w;
input en;
output [3:0]y;
reg [3:0]y;
always@(w or en)
begin
	if(en==0)
	y=4'b1111;
	else
	begin
		case(w)
		2'b00: y=4'b1110;
		2'b01: y=4'b1101;
		2'b10: y=4'b1011;
		2'b11: y=4'b0111;
		endcase
	end
end
endmodule

module dec4to16activelowusing2to4activelow(nw,ny,en2);
	input [3:0]nw;
	input en2;
	output [15:0]ny;
	reg [15:0]ny;
	wire [4:1]ecomp,e;
	dec2to4 stage0(nw[1:0],ecomp[4:1],en2);
	assign e[4]=~ecomp[4];
	assign e[3]=~ecomp[3];
	assign e[2]=~ecomp[2];
	assign e[1]=~ecomp[1];
	dec2to4 stage1(nw[3:2],ny[3:0],e[1]);
	dec2to4 stage2(nw[3:2],ny[7:4],e[2]);
	dec2to4 stage3(nw[3:2],ny[11:8],e[3]);
	dec2to4 stage4(nw[3:2],ny[15:12],e[4]);
endmodule
