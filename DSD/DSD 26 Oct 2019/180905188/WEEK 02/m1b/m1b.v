module m1b(A,B,C,D,f); 
input A,B,C,D; 
output f; 
assign f=(B&~C&~D)|(~B&C)|(~B&D);
endmodule
