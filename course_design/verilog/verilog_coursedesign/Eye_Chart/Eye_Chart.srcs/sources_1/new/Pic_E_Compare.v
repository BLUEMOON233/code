`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/23 13:33:36
// Design Name: 
// Module Name: Pic_E_Compare
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


module Pic_E_Compare(
    input [2:0] vision,
    input [1:0] sel,
    input [9:0] x,
    input [9:0] y,
    output reg [11:0] pix_data
    );
    reg [8:0] pix_range;
    always @(*) begin
        case(vision)
            3'd0:pix_range = 300;
            3'd1:pix_range = 240;
            3'd2:pix_range = 200;
            3'd3:pix_range = 160;
            3'd4:pix_range = 100;
            3'd5:pix_range = 80;
            3'd6:pix_range = 60;
            3'd7:pix_range = 40;
        endcase
    end
    
    always @(*) begin
        case(sel)
            2'd0: begin
                if(((480 - pix_range)/2 + pix_range/5*0 <= y && y <= (480 - pix_range)/2 + pix_range/5*1-1) && ((320 - pix_range)/2 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*1 <= y && y <= (480 - pix_range)/2 + pix_range/5*2-1) && ((320 - pix_range)/2 + 0 <= x && x <= (320 - pix_range)/2 + pix_range/5-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*2 <= y && y <= (480 - pix_range)/2 + pix_range/5*3-1) && ((320 - pix_range)/2 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*3 <= y && y <= (480 - pix_range)/2 + pix_range/5*4-1) && ((320 - pix_range)/2 + 0 <= x && x <= (320 - pix_range)/2 + pix_range/5-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range/5*5-1) && ((320 - pix_range)/2 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*0 <= y && y <= (480 - pix_range)/2 + pix_range/5*1-1) && (320+(320 - pix_range)/2 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*1 <= y && y <= (480 - pix_range)/2 + pix_range/5*2-1) && (320+(320 - pix_range)/2 + 0 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*2 <= y && y <= (480 - pix_range)/2 + pix_range/5*3-1) && (320+(320 - pix_range)/2 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*3 <= y && y <= (480 - pix_range)/2 + pix_range/5*4-1) && (320+(320 - pix_range)/2 + 0 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range/5*5-1) && (320+(320 - pix_range)/2 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(0 <= x && x <= 319) pix_data = 12'h0f0;
                else pix_data = 12'hf00;
            end
            2'd1: begin
                if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*0 <= x && x <= (320 - pix_range)/2 + pix_range/5*1-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + 0 <= y && y <= (480 - pix_range)/2 + pix_range/5-1) && ((320 - pix_range)/2 + pix_range/5*1 <= x && x <= (320 - pix_range)/2 + pix_range/5*2-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*2 <= x && x <= (320 - pix_range)/2 + pix_range/5*3-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + 0 <= y && y <= (480 - pix_range)/2 + pix_range/5-1) && ((320 - pix_range)/2 + pix_range/5*3 <= x && x <= (320 - pix_range)/2 + pix_range/5*4-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*4 <= x && x <= (320 - pix_range)/2 + pix_range/5*5-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*0 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*1-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + 0 <= y && y <= (480 - pix_range)/2 + pix_range/5-1) && (320+(320 - pix_range)/2 + pix_range/5*1 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*2-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*2 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*3-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + 0 <= y && y <= (480 - pix_range)/2 + pix_range/5-1) && (320+(320 - pix_range)/2 + pix_range/5*3 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*4-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*4 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*5-1)) pix_data = 12'h000;
                else if(0 <= x && x <= 319) pix_data = 12'h0f0;
                else pix_data = 12'hf00;
            end
            2'd2: begin
                if(((480 - pix_range)/2 + pix_range/5*0 <= y && y <= (480 - pix_range)/2 + pix_range/5*1-1) && ((320 - pix_range)/2 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*1 <= y && y <= (480 - pix_range)/2 + pix_range/5*2-1) && ((320 - pix_range)/2 + pix_range/5*4 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*2 <= y && y <= (480 - pix_range)/2 + pix_range/5*3-1) && ((320 - pix_range)/2 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*3 <= y && y <= (480 - pix_range)/2 + pix_range/5*4-1) && ((320 - pix_range)/2 + pix_range/5*4 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range/5*5-1) && ((320 - pix_range)/2 <= x && x <= (320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*0 <= y && y <= (480 - pix_range)/2 + pix_range/5*1-1) && (320+(320 - pix_range)/2 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*1 <= y && y <= (480 - pix_range)/2 + pix_range/5*2-1) && (320+(320 - pix_range)/2 + pix_range/5*4 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*2 <= y && y <= (480 - pix_range)/2 + pix_range/5*3-1) && (320+(320 - pix_range)/2 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*3 <= y && y <= (480 - pix_range)/2 + pix_range/5*4-1) && (320+(320 - pix_range)/2 + pix_range/5*4 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range/5*5-1) && (320+(320 - pix_range)/2 <= x && x <= 320+(320 - pix_range)/2 + pix_range-1)) pix_data = 12'h000;
                else if(0 <= x && x <= 319) pix_data = 12'h0f0;
                else pix_data = 12'hf00;
            end
            2'd3: begin
                if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*0 <= x && x <= (320 - pix_range)/2 + pix_range/5*1-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*1 <= x && x <= (320 - pix_range)/2 + pix_range/5*2-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*2 <= x && x <= (320 - pix_range)/2 + pix_range/5*3-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*3 <= x && x <= (320 - pix_range)/2 + pix_range/5*4-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((320 - pix_range)/2 + pix_range/5*4 <= x && x <= (320 - pix_range)/2 + pix_range/5*5-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*0 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*1-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*1 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*2-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*2 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*3-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*3 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*4-1)) pix_data = 12'h000;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && (320+(320 - pix_range)/2 + pix_range/5*4 <= x && x <= 320+(320 - pix_range)/2 + pix_range/5*5-1)) pix_data = 12'h000;
                else if(0 <= x && x <= 319) pix_data = 12'h0f0;
                else pix_data = 12'hf00;
            end
        endcase
    end

endmodule
