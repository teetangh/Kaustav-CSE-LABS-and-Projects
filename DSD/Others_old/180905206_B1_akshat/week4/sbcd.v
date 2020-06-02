module sbcd(x,y,cin,s,cout);
input [3:0] x,y;
input cin;
output cout;
output [3:0] s;
wire [3:0] z,ss;
wire [3:1] c,cc;
wire k,c4,r;
FA stage0(cin,x[0],y[0],z[0],c[1]);
FA stage1(c[1],x[1],y[1],z[1],c[2]);
FA stage2(c[2],x[2],y[2],z[2],c[3]);
FA stage3(c[3],x[3],y[3],z[3],c4);
assign k = c4|(z[3]&z[2])|(z[3]&z[1]);
assign ss[0] = 0;
assign ss[1] = k;
assign ss[2] = k;
assign ss[3] = 0;
FA stage00(cin,z[0],ss[0],s[0],cc[1]);
FA stage01(cc[1],z[1],ss[1],s[1],cc[2]);
FA stage02(cc[2],z[2],ss[2],s[2],cc[3]);
FA stage03(cc[3],z[3],ss[3],s[3],r);
assign cout = k;
endmodule

module FA(cin,a,b,s,cout);
input a,b,cin;
output s,cout;
assign s = a^b^cin;
assign cout = (a&b)|(b&cin)|(a&cin);
endmodule




