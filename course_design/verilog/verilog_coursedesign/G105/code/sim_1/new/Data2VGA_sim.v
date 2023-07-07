`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/25 02:16:05
// Design Name: 
// Module Name: Data2VGA_sim
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


module Data2VGA_sim(
    );
    reg clk = 0;
    wire [9:0] pix_x;
    wire [9:0] pix_y;
    wire [11:0] vga_data;
    wire Hsync, Vsync;
    
    Data2VGA d2v(
        .clk(clk),
        .pix_data(12'hfff),
        .pix_x(pix_x),
        .pix_y(pix_y),
        .vga_data(vga_data),
        .Hsync(Hsync),
        .Vsync(Vsync)
    );
    
    initial begin
        #0      clk = 1;
        #100000 $finish;
    end
    always #1 clk = ~clk;
endmodule
