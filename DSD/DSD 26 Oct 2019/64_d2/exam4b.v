

module dff2(D,Clock,Q);
	input D,Clock;
	output Q;
	reg Q;
	always @( posedge Clock)
		Q<=D;
endmodule

module exam4b(f,clock);
input clock;
output [7:0]f;
reg [7:0]f;
always @f
dff2 st0(~f[3],clock,f[0]);
dff2 st1(f[0],clock,f[1]);
dff2 st2(f[1],clock,f[2]);
dff2 st3(f[2],clock,f[3]);
endmodule

