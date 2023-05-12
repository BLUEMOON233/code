`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/12 15:05:24
// Design Name: 
// Module Name: mux41_hex7
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


module mux41_hex7(
    input [15: 0] x,
    input [3: 0] btn,
    output [6: 0] seg,
    output [3: 0] an
    );
    
    wire [1: 0] sel;
    wire [3: 0] y;
    wire inv;
    
    priority_encoder_42 pe42(.D(btn), .Y(sel), .inv(inv));
    decoder_24 d24(.D(sel), .inv(inv), .Y(an));
    mux41 m41(.SEL(sel), .D0(x[3: 0]), .D1(x[7: 4]), .D2(x[11: 8]), .D3(x[15: 12]), .Y(y));
    hex_7 h7(.D(y), .seg(seg));
    
endmodule
