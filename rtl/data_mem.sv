module data_mem #(
    parameter DATA_WIDTH = 32
)(
    input   logic                      clk,
    input logic [DATA_WIDTH-1:0] ALUResult, 
    input logic [DATA_WIDTH-1:0] WriteData,
    input logic                        WE,
    output logic [DATA_WIDTH-1:0]      RD 
);
    logic [DATA_WIDTH-1:0] mem_array [(2**DATA_WIDTH)-1:0];

    // Read
    assign RD = mem_array[ALUResult];

    // Write
    always_ff @(posedge clk) begin
        if (WE)
            mem_array[ALUResult] <= WriteData;
    end
endmodule
