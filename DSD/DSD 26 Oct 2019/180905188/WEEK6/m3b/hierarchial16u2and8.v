module hierarchial16u2and8(hw,hs,hf);
   input [15:0]hw;
   input [3:0]hs;
   output hf;
   wire [1:0]k;
   
   mux8to1 stage0(hw[7:0],hs[2:0],k[0]);
   mux8to1 stage1(hw[15:8],hs[2:0],k[1]);
   mux2to1 stage2(k[0], k[1], hs[3], hf);
endmodule
   
//modules dont have parameter naming conflict but functions do have
module mux8to1(w,s,f);
  input [7:0]w;
  input [2:0]s;
  output f;
  reg f;
always @(w or s)
begin
case(s)
0:f=w[0];
1:f=w[1];
2:f=w[2];
3:f=w[3];
4:f=w[4];
5:f=w[5];
6:f=w[6];
7:f=w[7];
endcase
end
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

