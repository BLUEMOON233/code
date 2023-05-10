`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 10:16:27
// Design Name: 
// Module Name: mux41
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


module mux41(
    input D0, D1, D2, D3,
    input [1: 0] SEL,
    output Y
    );

    wire x, y;

    mux21 a(.D0(D0), .D1(D1), .SEL(SEL[0]), .Y(x));
    mux21 b(.D0(D2), .D1(D3), .SEL(SEL[0]), .Y(y));
    mux21 c(.D0(x), .D1(y), .SEL(SEL[1]), .Y(Y));

endmodule
