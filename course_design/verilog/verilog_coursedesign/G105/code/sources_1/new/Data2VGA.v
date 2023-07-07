`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/22 20:54:05
// Design Name: 
// Module Name: Data2VGA
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


module Data2VGA(
    input clk,
    input [11:0] pix_data,
    output [9:0] pix_x,
    output [9:0] pix_y,
    output [11:0] vga_data,
    output Hsync,
    output Vsync
    );
    parameter   H_SYNC  = 96,
                H_BACK  = 48,
                H_VALID = 640,
                H_FRONT = 16,
                H_TOTAL = 800;
    parameter   V_SYNC  = 2,
                V_BACK  = 33,
                V_VALID = 480,
                V_FRONT = 10,
                V_TOTAL = 525;
                
    reg [9:0] x_cnt = 0;
    reg [9:0] y_cnt = 0;
    always @(posedge clk) begin
        if (x_cnt == H_TOTAL - 1'd1) x_cnt <= 10'd0;
        else x_cnt <= x_cnt + 1'd1;
    end
    assign Hsync = (x_cnt >= H_SYNC);
    always @(posedge clk) begin
        if (y_cnt == V_TOTAL - 1'd1 && x_cnt == H_TOTAL - 1'd1) y_cnt <= 10'd0;
        else if (x_cnt == H_TOTAL - 1'd1) y_cnt <= y_cnt + 1'd1;
        else y_cnt <= y_cnt;
    end
    assign Vsync = (y_cnt >= V_SYNC);
    assign pix_valid = (((H_SYNC + H_BACK <= x_cnt)
                     &&(x_cnt <= H_SYNC + H_BACK + H_VALID - 1'd1))
                     &&((V_SYNC + V_BACK <= y_cnt)
                     &&(y_cnt <= V_SYNC + V_BACK + V_VALID - 1'd1)));
    assign pix_data_req = (((H_SYNC + H_BACK - 1'd1 <= x_cnt)
                        &&(x_cnt <= H_SYNC + H_BACK + H_VALID - 2'd2))
                        &&((V_SYNC + V_BACK <= y_cnt)
                        &&(y_cnt <= V_SYNC + V_BACK + V_VALID - 1'd1)));
    assign pix_x = (pix_data_req)?(x_cnt - (H_SYNC + H_BACK - 1'b1)):10'd1000;
    assign pix_y = (pix_data_req)?(y_cnt - (V_SYNC + V_BACK)):10'd1000;
    assign vga_data = (pix_valid)?pix_data:12'h000;
endmodule
