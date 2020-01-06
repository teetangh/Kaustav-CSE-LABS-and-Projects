module dff(d,reset,clk,q);
input d,clk,reset;
output q;
reg q;
always @ (posedge reset or posedge clk)
begin
if(reset)
q=0;
else
q=d;
end
endmodule
