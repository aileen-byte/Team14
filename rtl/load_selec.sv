module load_selec #(
    parameter DATA_WIDTH = 32
)(
    input  logic [1:0]                 size,
    input  logic [1:0]                 byte_num,
    input  logic [DATA_WIDTH-1:0]      mem_data,
    output logic [DATA_WIDTH-1:0]      load_data
);

logic [7:0] selected_byte;

always_comb begin
    case (byte_num)
        2'b00: selected_byte = mem_data[7:0];
        2'b01: selected_byte = mem_data[15:8];
        2'b10: selected_byte = mem_data[23:16];
        2'b11: selected_byte = mem_data[31:24];
    endcase
end

always_comb begin
    case (size)
        2'b00: begin // LBU
                load_data = {24'b0, selected_byte};
        end
        2'b01: begin // LB
            load_data = {{24{selected_byte[7]}}, selected_byte};
        end
        2'b10: begin // LW
            load_data = mem_data;
        end
        default: begin
            load_data = 32'b0;
        end
    endcase
end

endmodule
