`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 00:31:24
// Design Name: 
// Module Name: counter_mod10
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


module counter_mod10(
    input clk, clr, en,
    output [3: 0] D,
    output out
    );
    reg [3: 0] regN;
    always @(posedge clk) begin
        if(clr || regN == 9) regN <= 4'b0000;
        else regN <= regN + en;
    end
    assign D = regN;
    assign out = (regN == 9) ? 1 : 0;
endmodule
