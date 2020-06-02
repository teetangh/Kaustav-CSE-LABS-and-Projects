module mux2to1(w,s,f);
input [1:0] w;
input s;
output f;
assign f = s?w[1]:w[0];
endmodule
module majfun(x,f);
input [2:0] x;
output f;
wire b;
wire [1:0] w,y,z,a;
assign a = {~x[0],x[0]};
mux2to1 st0(a,1,b);
assign y = {b,1'b1};
assign z = {1'b0,b};
mux2to1 st1(y,x[1],w[0]);
mux2to1 st2(z,x[1],w[1]);
mux2to1 st3(w,x[2],f);
endmodule
