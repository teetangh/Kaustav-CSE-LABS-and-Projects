module mux2to1(w,s,f);
input [1:0] w;
input s;
output f;
assign f = s?w[1]:w[0];
endmodule

