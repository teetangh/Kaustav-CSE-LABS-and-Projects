module btog(bin,gray);
input [3:0] bin;
output [3:0] gray;
wire [3:0] w;
assign gray[3]=bin[3];
assign w = {1'b0,1'b1,1'b1,1'b0};
mux4to1 st0(w,bin[3:2],gray[2]);
mux4to1 st1(w,bin[2:1],gray[1]);
mux4to1 st2(w,bin[1:0],gray[0]);
endmodule
module mux4to1(w,s,f);
input [3:0] w;
input [1:0] s;
output f;
assign f = s[0]?(s[1]?w[3]:w[1]):(s[1]?w[2]:w[0]);
endmodule
