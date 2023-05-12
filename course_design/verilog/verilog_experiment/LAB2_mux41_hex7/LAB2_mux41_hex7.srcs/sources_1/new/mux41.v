`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/12 14:51:28
// Design Name: 
// Module Name: mux41
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


module mux41(SEL, D0, D1, D2, D3, Y);
    parameter n = 4;
    input [1: 0] SEL;
    input [n - 1: 0] D0, D1, D2, D3;
    output reg [n - 1: 0] Y;
    
    always @(*) begin
        case(SEL)
            2'b00: Y = D0;
            2'b01: Y = D1;
            2'b10: Y = D2;
            2'b11: Y = D3;
        endcase
    end
endmodule
