module ForwardingUnit (
    input  logic [4:0] RsD,
    input  logic [4:0] RtD,

    input  logic [4:0] RsE,
    input  logic [4:0] RtE,

    input  logic [4:0] WriteRegM,
    input  logic [4:0] WriteRegW,

    input  logic       RegWriteM,
    input  logic       RegWriteW,

    output logic       ForwardAD,
    output logic       ForwardBD,
    output logic [1:0] ForwardAE,
    output logic [1:0] ForwardBE

);

always_comb begin 
    ForwardAD = (RsD != 5'd0) && RegWriteM && (RsD == WriteRegM); 
    ForwardBD = (RtD != 5'd0) && RegWriteM && (RtD == WriteRegM); 
end 

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
