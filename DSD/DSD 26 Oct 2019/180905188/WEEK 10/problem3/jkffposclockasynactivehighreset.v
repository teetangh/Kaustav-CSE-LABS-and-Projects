module jkffposclockasynactivehighreset(J,K,Clock,Resetn,Q);
	input J,K,Clock,Resetn;
	output Q;
	reg Q;
	always @(posedge Resetn or posedge Clock)
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

