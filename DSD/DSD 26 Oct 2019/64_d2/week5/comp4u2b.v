module comp4u2b(AeqB,AltB,AgtB,A,B);
input [4:0]A,B;
	wire  [4:0]i;
	output AeqB,AltB,AgtB;
comp4u2 stage0 (AeqB,AltB,A[1:0],B[1:0]);
comp4u2 stage1 (AeqB,AltB,A[3:2],B[3:2]);
endmodule
