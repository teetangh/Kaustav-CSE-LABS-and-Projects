module fulladder(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
wire p;
assign p = a^b;
assign s = p^cin;
assign cout = (a&b)|(b&cin)|(a&cin);
endmodule
module four_bitadd_sub(a,b,x,s,cout);
input [3:0] a,b;
input x;
output [3:0] s;
output cout;
wire [2:0] c;
wire [3:0] d;
assign d[0] = a[0]^x;
assign d[1] = a[1]^x;
assign d[2] = a[2]^x;
assign d[3] = a[3]^x;
fulladder s0(d[0],b[0],x,s[0],c[0]);
fulladder s1(d[1],b[1],c[0],s[1],c[1]);
fulladder s2(d[2],b[2],c[1],s[2],c[2]);
fulladder s3(d[3],b[3],c[2],s[3],cout);
endmodule
