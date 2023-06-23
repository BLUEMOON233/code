`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/22 20:58:21
// Design Name: 
// Module Name: Pic_E
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


module Pic_E(
    input [2:0] vision,
    input [1:0] sel,
    input [9:0] x,
    input [9:0] y,
    input sel_rgb_trans,
    input [11:0] rgb_trans,
    input [1:0] sel_background,
    output reg [11:0] pix_data
    );
    
    reg [8:0] pix_range;
    reg [11:0] E_clr = 12'h000;
    reg [11:0] bg_clr = 12'hfff;
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
        case(sel_background)
            2'd0:bg_clr = 12'hfff; 
            2'd1:bg_clr = 12'hf00;
            2'd2:bg_clr = 12'hfff; 
            2'd3:bg_clr = 12'h0f0; 
        endcase
    end
    
    always @(*) begin
        if(sel_rgb_trans) E_clr = rgb_trans;
        else E_clr = 12'h000;
    end
    
    always @(*) begin
        case(sel)
            2'd0: begin
                if(((480 - pix_range)/2 + pix_range/5*0 <= y && y <= (480 - pix_range)/2 + pix_range/5*1-1) && ((640 - pix_range)/2 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*1 <= y && y <= (480 - pix_range)/2 + pix_range/5*2-1) && ((640 - pix_range)/2 + 0 <= x && x <= (640 - pix_range)/2 + pix_range/5-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*2 <= y && y <= (480 - pix_range)/2 + pix_range/5*3-1) && ((640 - pix_range)/2 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*3 <= y && y <= (480 - pix_range)/2 + pix_range/5*4-1) && ((640 - pix_range)/2 + 0 <= x && x <= (640 - pix_range)/2 + pix_range/5-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range/5*5-1) && ((640 - pix_range)/2 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else pix_data = bg_clr;
            end
            2'd1: begin
                if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*0 <= x && x <= (640 - pix_range)/2 + pix_range/5*1-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + 0 <= y && y <= (480 - pix_range)/2 + pix_range/5-1) && ((640 - pix_range)/2 + pix_range/5*1 <= x && x <= (640 - pix_range)/2 + pix_range/5*2-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*2 <= x && x <= (640 - pix_range)/2 + pix_range/5*3-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + 0 <= y && y <= (480 - pix_range)/2 + pix_range/5-1) && ((640 - pix_range)/2 + pix_range/5*3 <= x && x <= (640 - pix_range)/2 + pix_range/5*4-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*4 <= x && x <= (640 - pix_range)/2 + pix_range/5*5-1)) pix_data = E_clr;
                else pix_data = bg_clr;
            end
            2'd2: begin
                if(((480 - pix_range)/2 + pix_range/5*0 <= y && y <= (480 - pix_range)/2 + pix_range/5*1-1) && ((640 - pix_range)/2 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*1 <= y && y <= (480 - pix_range)/2 + pix_range/5*2-1) && ((640 - pix_range)/2 + pix_range/5*4 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*2 <= y && y <= (480 - pix_range)/2 + pix_range/5*3-1) && ((640 - pix_range)/2 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*3 <= y && y <= (480 - pix_range)/2 + pix_range/5*4-1) && ((640 - pix_range)/2 + pix_range/5*4 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range/5*5-1) && ((640 - pix_range)/2 <= x && x <= (640 - pix_range)/2 + pix_range-1)) pix_data = E_clr;
                else pix_data = bg_clr;
            end
            2'd3: begin
                if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*0 <= x && x <= (640 - pix_range)/2 + pix_range/5*1-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*1 <= x && x <= (640 - pix_range)/2 + pix_range/5*2-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*2 <= x && x <= (640 - pix_range)/2 + pix_range/5*3-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 + pix_range/5*4 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*3 <= x && x <= (640 - pix_range)/2 + pix_range/5*4-1)) pix_data = E_clr;
                else if(((480 - pix_range)/2 <= y && y <= (480 - pix_range)/2 + pix_range-1) && ((640 - pix_range)/2 + pix_range/5*4 <= x && x <= (640 - pix_range)/2 + pix_range/5*5-1)) pix_data = E_clr;
                else pix_data = bg_clr;
            end
        endcase
    end
endmodule
