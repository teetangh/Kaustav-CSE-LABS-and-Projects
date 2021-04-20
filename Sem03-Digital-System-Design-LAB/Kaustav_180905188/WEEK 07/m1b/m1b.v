module m1b(a,b,d,qf);
	input a, ,d;
	output qf;
    wire [1:0]x;
	wire [3:0]w;
	//assign x[1]=a;
	//assign x[0]=b;
assign x={a,b};
	assign w = {d,d,1'b0,1'b0};
	mux4to1 stage0(w,x,qf);
endmodule
module mux4to1(w,s,f);
   input [3:0]w;
   input [1:0]s;
   output f;
   reg f;
  //reg [1:0]k;
   always @(w or s)
    begin 
      f=(s[1]==0)?((s[0]==0)?w[0]:w[1]):((s[0]==0)?w[2]:w[3]); 
    end
endmodule

