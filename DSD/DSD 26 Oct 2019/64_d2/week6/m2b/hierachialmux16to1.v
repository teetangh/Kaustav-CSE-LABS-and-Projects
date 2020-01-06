

module codecon(a,b);
input [3:0]a;
output [3:0]b;
reg [3:0]b;
always@(a)
begin
mux4to1({0,0,0,a[0]},a[3:2],b[3]);




module mux4to1(w,s,f);
   input [3:0]w;
   input [1:0]s;
   output f;
   reg f;
   reg [1:0]k;
   always @(w or s)
    begin 
      f=(s[1]==0)?((s[0]==0)?w[0]:w[1]):((s[0]==0)?w[2]:w[3]); 
    end
endmodule


