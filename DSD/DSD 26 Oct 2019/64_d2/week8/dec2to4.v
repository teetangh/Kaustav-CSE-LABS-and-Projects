module dec2to4(w,e,y);
input [1:0]w;
input e;
output [3:0]y;
reg [3:0]y;
always @(w or e)
begin 
	if (w==0 && e==1)
      y=4'b0001;
   else if (w==1 && e==1)
      y=4'b0010;
 else if (w==2 && e==1)
      y=4'b0100;
 else if (w==3 && e==1)
      y=4'b1000;
end
endmodule
