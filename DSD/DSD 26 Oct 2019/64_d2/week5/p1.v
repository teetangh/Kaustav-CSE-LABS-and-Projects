module p1(a,b,c,d,f);
input a,b,c,d;
output f;
reg f;
always @ (a|b|c|d)
begin
casex(a|b|c)
3'b000 : f=0;
3'b001 : f=0;
3'b010 : f=1;
3'b011 : f=1;
3'b100 : f=1;
3'b101 : f=0;
3'b110 : f=1;
3'b111 : f=~d;
endcase
end 
endmodule
