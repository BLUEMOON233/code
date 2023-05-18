`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 10:29:24
// Design Name: 
// Module Name: stopwatch_top
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


module stopwatch_top(
    input clk,
    input [1: 0] sw,
    output [0: 6] seg,
    output [3: 0] an,
    output dp
    );

    stopwatch(
        .clk(clk),
        .clr(sw[0]),
        .en(sw[1]),
        .seg(seg),
        .an(an),
        .dp(dp)
    );
endmodule
