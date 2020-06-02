module graytobin(gray,bin);
parameter n=4;
input [n-1:0] gray;
output [n-1:0] bin;
reg [n-1:0] bin;
integer i;

always@(gray)
	begin
		bin[n-1]=gray[n-1];
		for (i=n-2;i>-1;i=i-1)
			begin
			bin[i]=gray[i]^bin[i+1];
		end
	end
endmodule
