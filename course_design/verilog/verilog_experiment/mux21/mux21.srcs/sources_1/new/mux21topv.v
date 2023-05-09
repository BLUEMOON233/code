`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/08 22:17:43
// Design Name: 
// Module Name: mux21topv
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


module mux21topv(
    input [2:0] sw,
    output [0:0] led
    );
    
    mux21a M1(
    .d0(sw[0]),
    .d1(sw[1]),
    .sel(sw[2]),
    .led(led[0])
    );
endmodule
