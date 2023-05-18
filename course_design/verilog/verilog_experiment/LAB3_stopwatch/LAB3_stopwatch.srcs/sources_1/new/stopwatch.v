`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 10:00:34
// Design Name: 
// Module Name: stopwatch
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


module stopwatch(
    input clk, clr, en,
    output [6: 0] seg,
    output [3: 0] an
    );

    wire [17: 0] clk_div;
    wire [3: 0] D0, D1, D2, D3;

    div(.clk(clk), .clk_div(clk_div));
    timer(
        .clk(clk),
        .clr(clr),
        .en(en),
        .d0(D0),
        .d1(D1),
        .d2(D2),
        .d3(D3)
    );
    display(
        .d0(D0),
        .d1(D1),
        .d2(D2),
        .d3(D3),
        .sel(clk_div[17: 16]),
        .seg(seg),
        .an(an)
    );
endmodule
