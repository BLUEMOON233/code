`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/23 14:16:04
// Design Name: 
// Module Name: RGB_Trans
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


module RGB_Trans(
    input clk,
    output reg [11:0] pix_data
    );
    reg [24: 0] clk_reg = 0;
    reg clk_div = 1;
    always @(posedge clk) begin
        if(clk_reg == 5000000 - 1) begin 
            clk_reg <= 25'd0;
            clk_div <= ~clk_div;
        end else clk_reg <= clk_reg + 1'd1;
    end
    reg [3:0] clr_cnt = 0;
    always @(posedge clk_div) begin
        if(clr_cnt == 4'd11) clr_cnt <= 4'd0;
        else clr_cnt <= clr_cnt + 1;
    end
    always @(posedge clk) begin
        case(clr_cnt)
            4'd0: pix_data <= 12'b1111_0000_0000;
            4'd1: pix_data <= 12'b1110_0000_0001;
            4'd2: pix_data <= 12'b1100_0000_0011;
            4'd3: pix_data <= 12'b1000_0000_0111;
            4'd4: pix_data <= 12'b0000_0000_1111;
            4'd5: pix_data <= 12'b0000_0001_1110;
            4'd6: pix_data <= 12'b0000_0011_1100;
            4'd7: pix_data <= 12'b0000_0111_1000;
            4'd8: pix_data <= 12'b0000_1111_0000;
            4'd9: pix_data <= 12'b0001_1110_0000;
            4'd10: pix_data <= 12'b0011_1100_0000;
            4'd11: pix_data <= 12'b0111_1000_0000;
        endcase 
    end
endmodule
