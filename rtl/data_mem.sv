module data_mem #(
    parameter DATA_WIDTH = 32,
    MEMORY_WIDTH = 131072
)(
    input   logic                      clk,
    input logic [DATA_WIDTH-1:0]       ALUResult, 
    input logic [DATA_WIDTH-1:0]       WriteData,
    input logic                        WE,
    input logic [1:0]                  MemWriteSize,    
    output logic [DATA_WIDTH-1:0]      RD 
);
    logic[7:0] mem_array [MEMORY_WIDTH-1:0];

    initial begin 
        $readmemh("data.hex", mem_array, 32'h10000);
    end 

    // Read
    logic [DATA_WIDTH-1:0] word_base = {ALUResult[DATA_WIDTH-1:2], 2'b00};
    assign RD = {mem_array[word_base+3], mem_array[word_base+2], mem_array[word_base+1], mem_array[word_base]};

    // Write
    always_ff @(posedge clk) begin
        if (WE) begin
            case(MemWriteSize)
                2'b00: begin //SB
                    mem_array[ALUResult] <= WriteData[7:0];
                end
                2'b01: begin //SH
                    mem_array[ALUResult] <= WriteData[7:0];
                    mem_array[ALUResult+1] <= WriteData[15:8];
                end
                2'b10: begin //SW
                    mem_array[ALUResult] <= WriteData[7:0];
                    mem_array[ALUResult+1] <= WriteData[15:8];
                    mem_array[ALUResult+2] <= WriteData[23:16];
                    mem_array[ALUResult+3] <= WriteData[31:24];
                end
                default: ;
            endcase
        end
    end
endmodule
