module tff(t,clk,reset,q);
input t,clk,reset;
output q;
reg q;
always @ (negedge reset or negedge clk)
begin
if(!reset)
q=0;
else
begin
if(t)
q=~q;
end
end
endmodule 

