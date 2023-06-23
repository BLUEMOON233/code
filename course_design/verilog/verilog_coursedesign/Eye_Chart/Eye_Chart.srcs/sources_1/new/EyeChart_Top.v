`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/22 19:06:24
// Design Name: 
// Module Name: EyeChart_Top
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


module EyeChart_Top(
    input clk,
    input btnU, btnL, btnR, btnD, btnC,
    input [6:0] sw,
    output [3:0] an,
    output [0:6] seg,
    output [3:0] vgaRed,
    output [3:0] vgaGreen,
    output [3:0] vgaBlue,
    output dp,
    output Hsync,
    output Vsync
    );
    
    wire vga_clk;
    wire [1:0] sel;
    wire [1:0] rst;
    wire [3:0] btn = {btnU, btnR, btnD, btnL};
    wire [9:0] pix_x;
    wire [9:0] pix_y;
    wire [11:0] pix_data_e;
    wire [11:0] pix_data_e_c;
    wire [11:0] pix_data_c;
    wire [11:0] pix_data_w;
    wire [11:0] rgb_trans;
    
    reg [11:0] pix_data;
    
    clk_wiz_0 cw0(
        .clk_in(clk),
        .clk_out(vga_clk)
    );
    
    Data2VGA d2v(
        .clk(vga_clk),
        .pix_data(pix_data),
        .pix_x(pix_x),
        .pix_y(pix_y),
        .vga_data({vgaRed, vgaGreen, vgaBlue}),
        .Hsync(Hsync),
        .Vsync(Vsync)
    );
    
    EyeChart_Control ec_c(
        .clk(vga_clk),
        .btn(btn),
        .sel(sel),
        .rst(rst)
    );
    
    always @(*) begin
        case(rst)
            2'd0:begin
                if(sw[5] == 0) pix_data = pix_data_e;
                else pix_data = pix_data_e_c;
            end
            2'd1:pix_data = pix_data_c;
            2'd2:pix_data = pix_data_w;
        endcase
    end
    Pic_E p_e(
        .vision(sw[2:0]),
        .sel(sel),
        .x(pix_x),
        .y(pix_y),
        .sel_rgb_trans(btnC),
        .rgb_trans(rgb_trans),
        .sel_background(sw[4:3]),
        .pix_data(pix_data_e)
    );
    Pic_E_Compare p_e_c(
        .vision(sw[2:0]),
        .sel(sel),
        .x(pix_x),
        .y(pix_y),
        .pix_data(pix_data_e_c)
    );
    Pic_Correct p_c(
        .in_x(pix_x),
        .in_y(pix_y),
        .pix_data(pix_data_c)
    );
    Pic_Wrong p_w(
        .in_x(pix_x),
        .in_y(pix_y),
        .pix_data(pix_data_w)
    );
    
    Vision2Seg v2s(
        .clk(clk),
        .sel_vis(sw[6]),
        .vision(sw[2:0]),
        .seg(seg),
        .an(an),
        .dp(dp)
    );
    
    RGB_Trans(
        .clk(clk),
        .pix_data(rgb_trans)
    );
    
endmodule
