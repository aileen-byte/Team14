module EX_ME_Reg #(
    parameter DATA_WIDTH = 32
)(
    input  logic                clk,
    input  logic                reset,

    // Control + data from EX stage
    input  logic                RegWriteE,
    input  logic                MemtoRegE,
    input  logic                MemWriteE,
    input  logic [DATA_WIDTH-1:0] ALUOutE,
    input  logic [DATA_WIDTH-1:0] WriteDataE,
    input  logic [4:0]           WriteRegE,
    input  logic [1:0]           ResultSrcE,
    input  logic [DATA_WIDTH-1:0] ExtImmE,
    input  logic [DATA_WIDTH-1:0] PCPlus4E,

    // Store size for memory writes
    input  logic [1:0]           StoreSizeE,
    output logic [1:0]           StoreSizeM,

    // Flush signal from control logic
    input  logic                 FlushM,

    // Outputs to MEM stage
    output logic                RegWriteM,
    output logic                MemtoRegM,
    output logic                MemWriteM,
    output logic [1:0]          ResultSrcM,
    output logic [DATA_WIDTH-1:0] ExtImmM,
    output logic [DATA_WIDTH-1:0] PCPlus4M,
    output logic [DATA_WIDTH-1:0] ALUOutM,
    output logic [DATA_WIDTH-1:0] WriteDataM,
    output logic [4:0]          WriteRegM
);

    always_ff @(posedge clk) begin

        if (reset) begin
            RegWriteM  <= 0;
            MemtoRegM  <= 0;
            MemWriteM  <= 0;
            ResultSrcM <= 0;
            StoreSizeM <= 0;

            ALUOutM    <= 0;
            WriteDataM <= 0;
            WriteRegM  <= 0;
            ExtImmM    <= 0;
            PCPlus4M   <= 0;
        end

        else if (FlushM) begin
            // Bubble: kill control, avoid dependency pollution
            RegWriteM  <= 0;
            MemtoRegM  <= 0;
            MemWriteM  <= 0;
            ResultSrcM <= 0;
            StoreSizeM <= 0;
            WriteRegM  <= 0; 
            ALUOutM    <= 0;
            WriteDataM <= 0;

            // Data values can stay unchanged
        end

        else begin
            RegWriteM  <= RegWriteE;
            MemtoRegM  <= MemtoRegE;
            MemWriteM  <= MemWriteE;
            ResultSrcM <= ResultSrcE;
            StoreSizeM <= StoreSizeE;

            ALUOutM    <= ALUOutE;
            WriteDataM <= WriteDataE;
            WriteRegM  <= WriteRegE;
            ExtImmM    <= ExtImmE;
            PCPlus4M   <= PCPlus4E;
        end

    end

endmodule

