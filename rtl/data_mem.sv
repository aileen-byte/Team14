module data_mem #(
    parameter DATA_WIDTH = 32,
    MEMORY_WIDTH = 131072
)(
    input   logic                      clk,
    input logic [DATA_WIDTH-1:0] ALUResult, 
    input logic [DATA_WIDTH-1:0] WriteData,
    input logic                        WE,
    input logic [1:0]                  MemWriteSize,    
    output logic [DATA_WIDTH-1:0]      RD 
);
    logic[7:0] mem_array [MEMORY_WIDTH-1:0];

    initial begin 
        $readmemh("data.hex", mem_array, 32'h10000);
    end 

    // Read
    assign RD = {mem_array[ALUResult+3], mem_array[ALUResult+2], mem_array[ALUResult+1], mem_array[ALUResult]};

    // Write
    always_ff @(posedge clk) begin
        if (WE) begin
            if (MemWriteSize == 2'b00) // byte
                mem_array[ALUResult] <= WriteData[7:0];
            else if (MemWriteSize == 2'b01) begin // half-word
                mem_array[ALUResult] <= WriteData[7:0];
                mem_array[ALUResult+1] <= WriteData[15:8];
            end
            else if (MemWriteSize == 2'b10) // word
            begin
                mem_array[ALUResult] <= WriteData[7:0];
                mem_array[ALUResult+1] <= WriteData[15:8];
                mem_array[ALUResult+2] <= WriteData[23:16];
                mem_array[ALUResult+3] <= WriteData[31:24];
            end
        end
    end
endmodule
