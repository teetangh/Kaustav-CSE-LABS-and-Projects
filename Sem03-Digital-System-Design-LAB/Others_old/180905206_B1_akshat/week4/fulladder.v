module fulladder(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
wire p;
assign p = a^b;
assign s = p^cin;
assign cout = (a&b)|(b&cin)|(a&cin);
endmodule
