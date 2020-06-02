module gray2bin(G,B);
parameter n=4;
input [n:0]G;
output [n:0]B;
reg [n:0]B;
integer k;

always@(G)
begin
B[n]=G[n];
for(k=n-1;k>=0;k=k-1)
begin
B[k]=(B[k+1]^G[k]);
end
end
endmodule
