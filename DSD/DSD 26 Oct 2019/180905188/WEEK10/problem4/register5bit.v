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
module register5bit(x,f,RegisterClock);
	input [4:0]x;
	output [4:0]f;
	reg [4:0]f;
	input RegisterClock;
	dffposclockasynactivehighreset stage0(x[0],RegisterClock,0,f[0]);
	dffposclockasynactivehighreset stage1(x[1],RegisterClock,0,f[1]);
	dffposclockasynactivehighreset stage2(x[2],RegisterClock,0,f[2]);
	dffposclockasynactivehighreset stage3(x[3],RegisterClock,0,f[3]);
	dffposclockasynactivehighreset stage4(x[4],RegisterClock,0,f[4]);
endmodule
