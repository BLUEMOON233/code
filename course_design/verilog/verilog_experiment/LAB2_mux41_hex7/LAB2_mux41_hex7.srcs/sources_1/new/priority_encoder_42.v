`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/12 15:10:03
// Design Name: 
// Module Name: priority_encoder_42
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


module priority_encoder_42(
    input [3: 0] D,
    output reg [1: 0] Y,
    output inv
    );
    
    assign inv = D[0] | D[1] | D[2] | D[3];
    
    always @(*) begin
        casex(D)
            4'b1xxx: Y = 2'b11;
            4'bx1xx: Y = 2'b10;
            4'bxx1x: Y = 2'b01;
            4'bxxx1: Y = 2'b00;
        endcase
    end
endmodule
