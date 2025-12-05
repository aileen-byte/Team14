module load_selec #(
    parameter DATA_WIDTH = 32
)(
    input logic [2:0] funct3,
    input logic [1:0] byte_num,
    input logic [DATA_WIDTH-1:0] mem_data,
    output logic [DATA_WIDTH-1:0] load_data
);



always_comb begin
    case (funct3)
        3'b000: begin // LB
            load_data = {{24{mem_data[7]}}, mem_data[7:0]};
        end
        3'b001: begin // LH
            load_data = {{16{mem_data[15]}}, mem_data[15:0]};
        end
        3'b010: begin // LW
            load_data = mem_data;
        end
        3'b100: begin // LBU
                load_data = {24'b0, mem_data[7:0]};
        end
        3'b101: begin // LHU
            load_data = {16'b0, mem_data[15:0]};
        end
        default: begin
            load_data = 32'b0; // Default case (should not occur)
        end
    endcase
end

endmodule
