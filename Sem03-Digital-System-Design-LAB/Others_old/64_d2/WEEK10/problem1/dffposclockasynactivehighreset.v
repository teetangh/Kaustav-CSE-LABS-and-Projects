module dffposclockasynactivehighreset(D,Clock,Resetn,Q);
	input D,Clock,Resetn;
	output Q;
	reg Q;
	always @(posedge Resetn or posedge Clock)
	if(Resetn)
		Q<=0;
	else
		Q<=D;
endmodule
