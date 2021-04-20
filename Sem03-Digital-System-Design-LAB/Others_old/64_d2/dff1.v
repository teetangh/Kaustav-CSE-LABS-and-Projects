module dff1(D,Clock,Q);
	input D,Clock;
	output Q;
	reg Q;
	always @( posedge Clock)
		Q<=D;
endmodule



