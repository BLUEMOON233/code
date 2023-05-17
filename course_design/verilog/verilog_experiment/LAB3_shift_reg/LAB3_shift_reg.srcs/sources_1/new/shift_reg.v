`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/17 22:41:48
// Design Name: 
// Module Name: shift_reg
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


module shift_reg(
    input [1: 0] sel,
    input [7: 0] D,
    input nclr, Dsr, Dsl, clk,
    output reg [7: 0] out
    );

    always @(posedge clk or negedge nclr) begin
        if(~nclr) out <= 8'b00000000;
        else
            case (sel)
                2'b01: out <= {Dsr, out[7: 1]};
                2'b10: out <= {out[6: 0], Dsl};
                2'b11: out <= D;
            endcase
    end
endmodule
