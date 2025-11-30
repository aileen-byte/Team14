module HazardUnit (
    input logic [4:0]         RsD,
    input logic [4:0]         RtD, 

    input logic [4:0]         RsE, 
    input logic [4:0]         RtE,

    input logic [4:0]         WriteRegE, 
    input logic [4:0]         WriteRegM, 
    
    input logic         MemtoRegE,
    input logic         MemtoRegM,
    input logic         RegWriteE,
    input logic         RegWriteM,
    

    input logic         BranchD, 

    output logic StallF, 
    output logic StallD, 
    output logic FlushE, 
); 

logic lwstall; 
logic branchstall; 

always_comb begin 
    lwstall = MemtoRegE && ((RsD == RtE) || (RtD == RtE)); 
end 

always_comb begin 
    branchstall = (BranchD && RegWriteE && ((WriteRegE == RsD) || (WriteRegE == RtD))) || (BranchD && MemtoRegM && ((WriteRegM == RsD) || (WriteRegM == RtD))); 
end

always_comb begin
    stallF = lwstall | branchstall;
    stallD = lwstall | branchstall;
    flushE = lwstall | branchstall;
end 

endmodule 
