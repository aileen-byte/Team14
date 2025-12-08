module HazardUnit (
    input logic [4:0] RsD, RtD,
    input logic [4:0] RsE, RtE,
    input logic [4:0] WriteRegE, WriteRegM,
    input logic MemtoRegE, MemtoRegM,
    input logic RegWriteE, RegWriteM,
    input logic BranchD,
    input logic JalrD,

    output logic StallF, 
    output logic StallD, 
    output logic FlushE_hazard
);

logic lwstall; 
logic branchstall; 
logic jalrstall;

// LOAD-USE
always_comb begin
    lwstall = MemtoRegE &&
              (WriteRegE != 5'd0) &&
              ((RsD == WriteRegE) || (RtD == WriteRegE));
end

// BRANCH STALL: only stall on EX result or MEM-stage load
always_comb begin
    branchstall = BranchD &&
                  (
                     (RegWriteE && (WriteRegE == RsD || WriteRegE == RtD)) ||
                     (MemtoRegM && (WriteRegM == RsD || WriteRegM == RtD))
                  );
end

// JALR stall: same as branch but only depends on RsD
always_comb begin
    jalrstall = JalrD &&
                (
                   (RegWriteE && WriteRegE == RsD) ||
                   (MemtoRegM && WriteRegM == RsD)
                );
end

assign StallF = lwstall | branchstall | jalrstall;
assign StallD = lwstall | branchstall | jalrstall;
assign FlushE_hazard = lwstall | branchstall | jalrstall;

endmodule

