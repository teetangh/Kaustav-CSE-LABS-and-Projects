module exam4c(f,clock);
input clock;
output [7:0]f;
reg [7:0]f;
always @(f)
dff3 st0(~f[3],clock,f[0]);
dff3 st1(f[0],clock,f[1]);
dff3 st2(f[1],clock,f[2]);
dff3 st3(f[2],clock,f[3]);
endmodule
module dff3(D,Clock,Q);
	input D,Clock;
	output Q;
	reg Q;
	always @( posedge Clock)
		Q<=D;
endmodule

