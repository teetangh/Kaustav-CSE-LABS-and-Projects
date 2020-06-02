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
module shiftregister6bit(userinput,f,RegisterClock);
	//input [5:0]x;
	//reg [5:0]x;
	output [5:0]f;
	//reg [5:0]f;
	input RegisterClock;
	input userinput;
	//assign x[0]=userinput;
	dffposclockasynactivehighreset stage0(userinput,RegisterClock,0,f[0]);
	//assign f[0]=x[1];
	dffposclockasynactivehighreset stage1(f[0],RegisterClock,0,f[1]);
	//assign f[1]=x[2];
	dffposclockasynactivehighreset stage2(f[1],RegisterClock,0,f[2]);
	//assign f[2]=x[3];
	dffposclockasynactivehighreset stage3(f[2],RegisterClock,0,f[3]);
	//assign f[3]=x[4];
	dffposclockasynactivehighreset stage4(f[3],RegisterClock,0,f[4]);
	//assign f[4]=x[5];
	dffposclockasynactivehighreset stage5(f[4],RegisterClock,0,f[5]);
endmodule

