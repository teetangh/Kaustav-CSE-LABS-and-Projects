module ex(T,clock);
input clock;
wire [3:0]f;
output[0:7]T;
reg [0:7]T;
flip st0(~f[3],clock,f[0]);
flip st1(f[0],clock,f[1]);
flip st2(f[1],clock,f[2]);
flip st3(f[2],clock,f[3]);
always@(f)
begin
case(f)
4'b1000 : T=8'b10000000;
4'b1100 : T=8'b01000000;
4'b1110 : T=8'b00100000;
4'b1111 : T=8'b00010000;
4'b0111 : T=8'b00001000;
4'b0011 : T=8'b00000100;
4'b0001 : T=8'b00000010;
4'b0000 : T=8'b00000001;
endcase
end
endmodule
module flip(D,Clock,Q);
	input D,Clock;
	output Q;
	reg Q;
	always @( posedge Clock)
		Q<=D;
endmodule


