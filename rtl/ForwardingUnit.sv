module ForwardingUnit (
    input  logic [4:0] RsE, //Rs1E
    input  logic [4:0] RtE, //Rs2E

    input  logic [4:0] WriteRegM, //RdM
    input  logic [4:0] WriteRegW, //RdW

    input  logic       RegWriteM,
    input  logic       RegWriteW,

    output logic [1:0] ForwardAE,
    output logic [1:0] ForwardBE
);

always_comb begin
    if ((RsE != 5'd0) && RegWriteM && (RsE == WriteRegM))
        ForwardAE = 2'b10;
    else if ((RsE != 5'd0) && RegWriteW && (RsE == WriteRegW))
        ForwardAE = 2'b01;
    else
        ForwardAE = 2'b00;

    if ((RtE != 5'd0) && RegWriteM && (RtE == WriteRegM))
        ForwardBE = 2'b10;
    else if ((RtE != 5'd0) && RegWriteW && (RtE == WriteRegW))
        ForwardBE = 2'b01;
    else
        ForwardBE = 2'b00;
end

endmodule
