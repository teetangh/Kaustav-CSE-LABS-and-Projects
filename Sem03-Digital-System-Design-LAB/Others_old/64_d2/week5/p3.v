module p3(a,b,c,d,g);
input a,b,c,d;
output g;
reg g;
always @ (a|b|c|d)
begin
casex(a|b)
2'b 00: g=(c|~d);
2'b 01: g=d;
2'b 10: g=0;
2'b 11: g=0;
endcase
end
endmodule
