module halfadder(a,b,s,cout);
input a,b;
output s,cout;
assign s = a^b;
assign cout = a&b;
endmodule
