


module dec3to8 (W, Y, En); 
input [1:0] W; input En; 
output [3:0] Y; reg [3:0] Y; 
integer k;
 always @(W or En) 
for (k = 3; k >= 3; k = k-1) 
if ((W == k) && (En == 1)) 
Y[k] = 1;
 else 
Y[k] = 0;
 endmodule


