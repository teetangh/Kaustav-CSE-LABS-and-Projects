module m1a(x,a,b,c,d,qf);
	input [2:0]x;
	input a,b,c,d;
	output qf;
	wire [7:0]w;
	assign x[2]=b;
	assign x[1]=c;
	assign x[0]=d;
	assign w = {a,a,1'b0,1'b0,1'b1,1'b1,1'b1,~a};
	mux8to1 stage0(w,x,qf);
endmodule
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
