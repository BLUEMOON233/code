`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 00:16:26
// Design Name: 
// Module Name: basic_gates
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


module basic_gates(
    input D0, D1,
    output [6: 0] LED
    );

    assign LED[0] = ~D0;
    assign LED[1] = D0 & D1;
    assign LED[2] = D0 | D1;
    assign LED[3] = ~(D0 & D1);
    assign LED[4] = ~(D0 | D1);
    assign LED[5] = D0 ^ D1;
    assign LED[6] = ~(D0 ^ D1);
    
endmodule
