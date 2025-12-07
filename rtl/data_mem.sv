module data_mem #(
    parameter DATA_WIDTH = 32,
    parameter MEMORY_WORDS = 65536
)(
    input   logic                      clk,
    input logic [DATA_WIDTH-1:0] ALUResult, 
    input logic [DATA_WIDTH-1:0] WriteData,
    input logic                        WE,
    output logic [DATA_WIDTH-1:0]      RD 
);
    logic [7:0] mem_array [0:MEMORY_WORDS-1];
    // Read
    assign RD = { mem_array[ALUResult + 3],
                  mem_array[ALUResult + 2],
                  mem_array[ALUResult + 1],
                  mem_array[ALUResult + 0] };

    // Write
    always_ff @(posedge clk) begin
        if (WE)
            mem_array[ALUResult] <= WriteData[7:0];
    end
endmodule 
