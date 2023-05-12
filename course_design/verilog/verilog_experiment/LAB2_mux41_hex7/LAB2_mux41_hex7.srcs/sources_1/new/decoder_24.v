`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/12 15:35:37
// Design Name: 
// Module Name: decoder_24
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module decoder_24(
    input [1: 0] D,
    input inv,
    output reg [3: 0] Y
    );
    
    always @(*) begin
        if (inv)
            case(D)
                2'b00: Y = 4'b1110;
                2'b01: Y = 4'b1101;
                2'b10: Y = 4'b1011;
                2'b11: Y = 4'b0111;
            endcase
        else
            Y = 4'b1111;
    end
endmodule
