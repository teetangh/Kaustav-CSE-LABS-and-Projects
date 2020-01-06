module tffnegclockasynactivelowreset(T,Clock,Resetn,Q);
	input T,Clock,Resetn;
	output Q;
	reg Q;
	always @(negedge Resetn or negedge Clock)
	if(!Resetn)
		Q<=0;
	else if(!T)
		Q<=Q;
	else
		Q<=~Q;
endmodule
