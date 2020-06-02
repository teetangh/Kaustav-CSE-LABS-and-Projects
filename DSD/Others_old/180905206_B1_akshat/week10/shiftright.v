module dff1(d,clk,q);
input d,clk;
output q;
reg q;
always @ (posedge clk)
begin
q<=d;
end
endmodule
module shiftright(w,clk,q);
input w,clk;
output [5:0]q;
dff1 st0(w,clk,q[5]);
dff1 st1(q[5],clk,q[4]);
dff1 st2(q[4],clk,q[3]);
dff1 st3(q[3],clk,q[2]);
dff1 st4(q[2],clk,q[1]);
dff1 st5(q[1],clk,q[0]);
endmodule
