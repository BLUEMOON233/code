`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/12 15:44:08
// Design Name: 
// Module Name: mux41_hex7_top
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


module mux41_hex7_top(
    input [15: 0] sw,
    input btnU, btnL, btnR, btnD,
    output [0: 6] seg,
    output [3: 0] an,
    output dp
    );
    
    assign dp = 1;
    
    mux41_hex7(
        .x(sw),
        .btn({btnD, btnR, btnL, btnU}),
        .seg(seg),
        .an(an)
    );
    
endmodule
