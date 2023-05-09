`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 00:17:07
// Design Name: 
// Module Name: basic_gates_top
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


module basic_gates_top(
    input [1: 0] sw,
    output [6: 0] led
    );

    basic_gates(
        .D0(sw[0]),
        .D1(sw[1]),
        .LED(led)
        );
    
endmodule
