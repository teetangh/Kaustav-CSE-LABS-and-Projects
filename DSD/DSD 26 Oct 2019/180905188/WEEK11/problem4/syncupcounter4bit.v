module tffposclockasynactivelowreset(T,Clock,Resetn,Q);
	input T,Clock,Resetn;
	output Q;
	reg Q;
	always @(negedge Resetn or posedge Clock)
	if(!Resetn)
		Q<=0;
	else if(T)
		Q<=~Q;
	else
		Q<=Q;
endmodule

module syncupcounter4bit(CounterClock,f);
	input CounterClock;
	output [3:0]f;
	tffposclockasynactivelowreset stage0(1,CounterClock,1,f[0]);
	tffposclockasynactivelowreset stage1(f[0],CounterClock,1,f[1]);
	tffposclockasynactivelowreset stage2(f[0]&f[1],CounterClock,1,f[2]);
	tffposclockasynactivelowreset stage3(f[0]&f[1]&f[2],CounterClock,1,f[3]);
endmodule
