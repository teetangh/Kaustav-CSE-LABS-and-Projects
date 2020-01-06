module hierachialmux16to1(hw,hs,hf);
   input [15:0]hw;
   input [3:0]hs;
   output hf;
   wire [3:0]k;
   mux4to1 stage0(hw[3:0], hs[1:0], k[0]);
   mux4to1 stage1(hw[7:4], hs[1:0], k[1]);
   mux4to1 stage2(hw[11:8], hs[1:0], k[2]);
   mux4to1 stage3(hw[15:12], hs[1:0], k[3]);
   mux4to1 stage4(k[3:0], hs[3:2], hf);	
endmodule

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


