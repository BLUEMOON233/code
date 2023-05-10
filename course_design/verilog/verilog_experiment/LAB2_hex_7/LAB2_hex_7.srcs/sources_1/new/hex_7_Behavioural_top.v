`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/11 00:02:31
// Design Name: 
// Module Name: hex_7_Behavioural_top
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


module hex_7_Behavioural_top(
    input [3: 0] sw,
    output [0: 6] seg,
    output [3: 0] an,
    output dp
    );

    assign an = 4'b0000;
    assign dp = 1;
    hex_7_Behavioural(.D(sw), .seg(seg));

endmodule
