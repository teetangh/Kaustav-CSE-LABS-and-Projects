module lab4_1c(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
wire p,q;
assign p = a^b;
assign q = a&b;
assign s = p^cin;
assign cout = (p&cin)|q;
endmodule
