module HazardUnit (
    input logic [4:0] RsD, RtD, //Rs1d, Rs2d
    input logic [4:0] WriteRegE, //RdE
    input logic [1:0] ResultSrcE,
    input logic [1:0] PCSrcE,

    output logic StallF, 
    output logic StallD, 
    output logic FlushD,
    output logic FlushE
);

logic lwstall; 
logic bj;

// Stall when a load hazard occurs
always_comb begin
    lwstall = (ResultSrcE == 2'b01) && (WriteRegE != 0) && ((RsD == WriteRegE) || (RtD == WriteRegE));
    StallF = lwstall;
    StallD = lwstall;
    if (PCSrcE != 2'b00) begin
        bj = 1'b1;
    end
    else begin 
        bj = 1'b0;
    end
    FlushD = bj;
    FlushE = lwstall || bj;
end

endmodule

