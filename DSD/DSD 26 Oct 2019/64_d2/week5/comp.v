module comp(AeqB,AltB,AgtB,A,B);
	input [4:0]A,B;
	wire  [4:0]i;
	output AeqB,AltB,AgtB;

	assign i[0]=~(A[0]^B[0]);
	assign i[1]=~(A[1]^B[1]);
	assign i[2]=~(A[2]^B[2]);
	assign i[3]=~(A[3]^B[3]);
	assign i[4]=~(A[4]^B[4]);

	assign AgtB = (A[4]&~B[4]) | (i[4]&A[3]&~B[3]) | (i[4]&i[3]&A[2]&~B[2]) |  (i[4]&i[3]&i[2]&A[1]&~B[1]) | (i[4]&i[3]&i[2]&i[1]&A[0]&~B[0]);
    assign AeqB = (i[4]&i[3]&i[2]&i[1]);
 	assign AltB = ~(AeqB | AgtB);

endmodule
