module pc_source(
    input  logic [1:0]  JumpType,
    input  logic [1:0]  BranchType,
    input  logic        ZeroE,
    output logic [1:0]  PCSrcE
);

always_comb begin
    case (JumpType)
        2'b01: begin // JAL
            PCSrcE = 2'b01; // Immediate
        end
        2'b10: begin // JALR
            PCSrcE = 2'b10; // JALR
        end
        default: PCSrcE = 2'b00;
    endcase
    case (BranchType)
        2'b10: begin // BEQ
            if (ZeroE)
                PCSrcE = 2'b01; // Immediate
            else
                PCSrcE = 2'b00; // Normal
        end
        2'b01: begin // BNE
            if (!ZeroE)
                PCSrcE = 2'b01; // Immediate
            else
                PCSrcE = 2'b00; // Normal
        end
        default: PCSrcE = 2'b00; // Normal
    endcase
end

endmodule

