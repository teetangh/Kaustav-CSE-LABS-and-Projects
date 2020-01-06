module twobit_multiplier(a,b,p);
input [1:0] a,b;
output [3:0] p;
wire cout;
wire [1:0] d,x,y;
assign x[0] = a[1]&b[0];
assign x[1] = 0;
assign y[0] = a[0]&b[1];
assign y[1] = a[1]&b[1];
assign p[0] = a[0]&b[0];
twobit_adder stage0(x,y,0,d,cout);
assign p[1] = d[0];
assign p[2] = d[1];
assign p[3] = cout;
endmodule

module twobit_adder(x,y,cin,s,cout);
input [1:0] x,y;
input cin;
output [1:0] s;
output cout;
wire c0;
fulladder stage0(x[0],y[0],cin,s[0],c0);
fulladder stage1(x[1],y[1],c0,s[1],cout);
endmodule
module fulladder(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
wire p;
assign p = a^b;
assign s = p^cin;
assign cout = (a&b)|(b&cin)|(a&cin);
endmodule

