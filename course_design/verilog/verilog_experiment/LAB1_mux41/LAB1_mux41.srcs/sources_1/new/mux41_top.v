`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 10:38:32
// Design Name: 
// Module Name: mux41_top
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


module mux41_top(
    input [5: 0] sw,
    output [0: 0] led
    );

    mux41(
        .D0(sw[2]),
        .D1(sw[3]),
        .D2(sw[4]),
        .D3(sw[5]),
        .SEL(sw[1: 0]),
        .Y(led)
    );
endmodule
