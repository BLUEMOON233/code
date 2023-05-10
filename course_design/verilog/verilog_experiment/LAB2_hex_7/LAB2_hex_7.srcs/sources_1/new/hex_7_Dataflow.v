`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 23:11:14
// Design Name: 
// Module Name: hex_7_Dataflow
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


module hex_7_Dataflow(
    input [3: 0] D,
    output [6: 0] seg
    );

    assign seg[6] = (~D[3] & ~D[2] & ~D[1] & D[0]) | (~D[3] & D[2] & ~D[1] & ~D[0]) | (D[3] & ~D[2] & D[1] & D[0]) | (D[3] & D[2] & ~D[1] & D[0]);
    assign seg[5] = (~D[3] & D[2] & ~D[1] & D[0]) | (D[2] & D[1] & ~D[0]) | (D[3] & D[1] & D[0]) | (D[3] & D[2] & ~D[0]);
    assign seg[4] = (~D[3] & ~D[2] & D[1] & ~D[0]) | (D[3] & D[2] & ~D[0]) | (D[3] & D[2] & D[1]);
    assign seg[3] = (~D[3] & ~D[2] & ~D[1] & D[0]) | (~D[3] & D[2] & ~D[1] & ~D[0]) | (D[2] & D[1] & D[0]) | (D[3] & ~D[2] & D[1] & ~D[0]);
    assign seg[2] = (~D[3] & D[0]) | (~D[2] & ~D[1] & D[0]) | (~D[3] & D[2] & ~D[1]);
    assign seg[1] = (~D[3] & ~D[2] & D[0]) | (~D[3] & ~D[2] & D[1]) | (~D[3] & D[1] & D[0]) | (D[3] & D[2] & ~D[1] & D[0]);
    assign seg[0] = (~D[3] & ~D[2] & ~D[1]) | (~D[3] & D[2] & D[1] & D[0]) | (D[3] & D[2] & ~D[1] & ~D[0]);
    
endmodule
