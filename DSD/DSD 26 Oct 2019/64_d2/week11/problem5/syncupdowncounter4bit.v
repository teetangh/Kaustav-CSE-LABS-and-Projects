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

module syncupdowncounter4bit(upordown,CounterClock,f);
	input CounterClock;
	input upordown;
	output [3:0]f;
	reg ta,tb,tc,td;
	always@(upordown)
	begin
		if(upordown)
		begin
			assign td=1;
			assign tc=f[0];
			assign tb=f[0]&f[1];
			assign ta=f[0]&f[1]&f[2];
		end
		else
		begin
			assign td=1;
			assign tc=~f[0];
			assign tb=~f[0]&~f[1];
			assign ta=~f[0]&~f[1]&~f[2];						
		end
	end
	tffposclockasynactivelowreset stage0(td,CounterClock,1,f[0]);
	tffposclockasynactivelowreset stage1(tc,CounterClock,1,f[1]);
	tffposclockasynactivelowreset stage2(tb,CounterClock,1,f[2]);
	tffposclockasynactivelowreset stage3(ta,CounterClock,1,f[3]);
endmodule

