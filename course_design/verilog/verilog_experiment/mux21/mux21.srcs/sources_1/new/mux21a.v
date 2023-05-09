`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/08 22:14:37
// Design Name: 
// Module Name: mux21a
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


module mux21a(
    input d0,
    input d1,
    input sel,
    output led
    );
    
    assign led = (~sel & d0) | (sel & d1);
endmodule
