module hierachialmux4to1(hw ,s, hf);
   input [3:0]hw;
input  [1:0]s;
   output hf;
   wire [1:0]k;
   mux2to1 stage0(hw[0], hw[1], s[0], k[0]);
   mux2to1 stage1(hw[2], hw[3], s[0], k[1]);
   mux2to1 stage2(k[0], k[1], s[1], hf);	
endmodule

module mux2to1 (w0, w1, s, f);
  input w0, w1, s;
  output f;
  reg f;
  always @(w0 or w1 or s)
    begin
     if(s==0)
  	 begin
 		f=w0;
     end
     else if(s==1)
	 begin
		f=w1;
 	 end
    end
endmodule

