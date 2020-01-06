module m2b(A,B,C,D,f); 
input A,B,C,D;
output f; 
assign f=(A|~B|C)&(~A|B|~D)&(~A|B|~C)&(~A|~B|C);
endmodule
