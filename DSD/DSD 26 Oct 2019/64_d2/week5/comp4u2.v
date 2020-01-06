module comp4u2(AeqB,AltB,AgtB,A,B);
	input [1:0]A,B;
	wire  [1:0]i;
	output AeqB,AltB,AgtB;

	assign i[0]=~(A[0]^B[0]);
	assign i[1]=~(A[1]^B[1]);
assign AgtB = (A[1]&~B[1]) | (i[1]&A[0]&~B[0]);
    assign AeqB = (i[1]&i[0]);
 	assign AltB = ~(AeqB | AgtB);
endmodule
