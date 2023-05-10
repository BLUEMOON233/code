`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 23:55:24
// Design Name: 
// Module Name: hex_7_Behavioural
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


module hex_7_Behavioural(
    input [3: 0] D,
    output reg [6: 0] seg
    );
    always @(*) begin
        case(D)
            0:  seg = 7'b0000001;
            1:  seg = 7'b1001111;
            2:  seg = 7'b0010010;
            3:  seg = 7'b0000110;
            4:  seg = 7'b1001100;
            5:  seg = 7'b0100100;
            6:  seg = 7'b0100000;
            7:  seg = 7'b0001111;
            8:  seg = 7'b0000000;
            9:  seg = 7'b0000100;
            10: seg = 7'b0001000;
            11: seg = 7'b1100000;
            12: seg = 7'b0110001;
            13: seg = 7'b1000010;
            14: seg = 7'b0110000;
            15: seg = 7'b0111000;
        endcase
    end
endmodule
