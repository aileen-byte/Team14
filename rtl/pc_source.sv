module pc_source(
    input  logic [1:0]  JumpType,
    input  logic [1:0]  BranchType,
    input  logic        ZeroE,
    output logic [1:0]  PCSrcE
);

always_comb begin
    if (JumpType == 2'b01) begin
        PCSrcE = 2'b01;
    end
    else if (JumpType == 2'b10) begin
        PCSrcE = 2'b10;
    end
    else if (BranchType == 2'b10) begin
        if (ZeroE) begin
            PCSrcE = 2'b01; // Immediate
        end
        else begin
            PCSrcE = 2'b00; // Normal
        end 
    end        
    else if (BranchType == 2'b01) begin
        if (!ZeroE) begin
            PCSrcE = 2'b01; // Immediate
        end
        else begin
            PCSrcE = 2'b00; // Normal
        end 
    end   
    else begin
        PCSrcE = 2'b00;
    end
end

endmodule

