module m1a(F,a,b,c,d);
input a,b,c,d;
output F;

and(t1,a,b);
or(t2,t1,c);
not(t3,t2);
and(t4,t3,d);

or(t5,t2,d);

and(F,t4,t5);

endmodule




