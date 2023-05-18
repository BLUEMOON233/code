`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 09:45:08
// Design Name: 
// Module Name: div
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


module div(
    input clk,
    output [17: 0] clk_div
    );
    reg [17: 0] clk_reg = 0;
    always @(posedge clk) begin
        clk_reg <= clk_reg + 1;
    end
    assign clk_div = clk_reg;
endmodule
