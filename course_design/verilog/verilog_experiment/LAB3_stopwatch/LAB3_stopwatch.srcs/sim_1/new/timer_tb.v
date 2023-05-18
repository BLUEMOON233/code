`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 18:46:27
// Design Name: 
// Module Name: timer_tb
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


module timer_tb(
    );
    reg clk, clr;
    wire [3: 0] d0, d1, d2, d3;

    timer t(
        .clk(clk),
        .clr(clr),
        .d0(d0),
        .d1(d1),
        .d2(d2),
        .d3(d3)
    );

    initial begin
        #0      clk = 1;
                clr = 0;
        #1300   clr = 1;
        #100    $finish;
    end
    always #1 clk = ~clk;
endmodule
