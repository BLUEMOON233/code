`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 09:54:08
// Design Name: 
// Module Name: display
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


module display(
    input [3: 0] d0, d1, d2, d3,
    input [1: 0] sel,
    output reg [6: 0] seg,
    output reg [3: 0] an,
    output reg dp
    );
    
    reg [3: 0] D;

    always @(*) begin
        case (sel)
            2'b00: an = 4'b1110;
            2'b01: an = 4'b1101;
            2'b10: an = 4'b1011;
            2'b11: an = 4'b0111;
        endcase
    end
    
    always @(*) begin
        case (sel)
            2'b00: D = d0;
            2'b01: D = d1;
            2'b10: D = d2;
            2'b11: D = d3;
        endcase
    end

    always @(*) begin
        case (sel)
            2'b00: dp = 1;
            2'b01: dp = 0;
            2'b10: dp = 1;
            2'b11: dp = 0;
        endcase
    end

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
