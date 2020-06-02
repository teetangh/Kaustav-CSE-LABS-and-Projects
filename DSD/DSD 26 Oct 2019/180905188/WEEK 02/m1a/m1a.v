module m1a(A,B,C,D,f); 
input A,B,C,D; 
output f; 
assign f=(B&~C&~D)|(~A&B)|(~B&C)|(C&D);
endmodule 
