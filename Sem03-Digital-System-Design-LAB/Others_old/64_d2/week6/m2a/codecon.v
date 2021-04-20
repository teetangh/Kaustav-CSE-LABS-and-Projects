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


module codecon(a,b);
input [3:0]a;
output [3:0]b;
reg [3:0]b;
mux4to1 stage4({a[0],a[0],a[0],a[0]},a[3:2],b[0]);
mux4to1 stage3({~a[1],1'b0,1'b0,a[1]},a[3:2],b[1]);
mux4to1 stage2({~a[1],1'b1,1'b1,1'b0},a[3:2],b[2]);
mux4to1 stage1({a[1],1'b0,1'b0,1'b0},a[3:2],b[3]);

endmodule






