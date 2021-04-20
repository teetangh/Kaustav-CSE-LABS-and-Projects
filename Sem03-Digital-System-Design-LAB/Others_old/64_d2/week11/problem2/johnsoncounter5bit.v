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
module johnsoncounter5bit(,Preset,f,RegisterClock);
	output [4:0]f;
	input RegisterClock;
	input Preset;
	reg x;
	always@(f)
	begin
	if(Preset)
		x=1;
	else
		x=~f[0];
	end
//	dffposclockasynactivehighreset stage0(1,RegisterClock,0,f[0]);
	dffposclockasynactivehighreset stage1(x,RegisterClock,0,f[4]);
	dffposclockasynactivehighreset stage2(f[4],RegisterClock,0,f[3]);
	dffposclockasynactivehighreset stage3(f[3],RegisterClock,0,f[2]);
	dffposclockasynactivehighreset stage4(f[2],RegisterClock,0,f[1]);
	dffposclockasynactivehighreset stage5(f[1],RegisterClock,0,f[0]);
endmodule


