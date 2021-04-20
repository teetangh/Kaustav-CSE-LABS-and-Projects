module bit2count1(d,clk,q);
input clk,d;
output q;
reg q;
always @ (negedge clk)
begin
q<=d;
end
endmodule

