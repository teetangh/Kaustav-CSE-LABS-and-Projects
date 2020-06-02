module m1b(f,a,b,c,d);
input a,b,c,d;
output f;

assign f = (((~((a&b)|c))&d)&(((a&b)|c)|d));

endmodule

