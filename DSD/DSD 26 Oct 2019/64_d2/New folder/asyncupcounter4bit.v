module jkffnegclockasynactivehighreset(J,K,Clock,Resetn,Q);
	input J,K,Clock,Resetn;
	output Q;
	reg Q;
	always @(posedge Resetn or negedge Clock)
	begin
	if(Resetn)
		Q<=0;
	else if((J==0)&&(K==0))
		Q<=Q;
	else if((J==0)&&(K==1))
		Q<=0;
	else if((J==1)&&(K==0))
		Q<=1;
	else if((J==1)&&(K==1))
		Q<=~Q;
	end
endmodule

module asyncupcounter4bit(CounterClock,f);
	input CounterClock;
	output [3:0]f;
	jkffnegclockasynactivehighreset stage0(1,1,CounterClock,0,f[0]);
	jkffnegclockasynactivehighreset stage1(1,1,f[0],0,f[1]);
	jkffnegclockasynactivehighreset stage2(1,1,f[1],0,f[2]);
	jkffnegclockasynactivehighreset stage3(1,1,f[2],0,f[3]);
endmodule
