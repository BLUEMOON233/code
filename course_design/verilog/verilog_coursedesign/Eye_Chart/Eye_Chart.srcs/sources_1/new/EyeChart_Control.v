`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/22 21:05:48
// Design Name: 
// Module Name: EyeChart_Control
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


module EyeChart_Control(
    input clk,
    input [3:0] btn,
    output [1:0] sel,
    output [1:0] rst
    );
    
    reg [1:0] sel_cnt = 2'd0;
    reg [1:0] sel_reg = 2'd0;
    reg [1:0] rst_reg = 2'd0;
    reg [25:0] reg_cnt = 26'd0;
    assign sel = sel_reg;
    assign rst = rst_reg;
    always @(posedge clk) begin
        sel_cnt <= sel_cnt + 1'd1;
    end
    always @(posedge clk) begin
        if(rst == 0) begin
            if(btn[0]||btn[1]||btn[2]||btn[3]) begin
                if((sel_reg == 0 && btn[2])||(sel_reg == 1 && btn[1])||(sel_reg == 2 && btn[0])||(sel_reg == 3 && btn[3])) rst_reg <= 2'd1;
                else rst_reg <= 2'd2;
            end
        end else begin
            if(reg_cnt == 50000000 - 1) begin
                rst_reg <= 2'd0;
                reg_cnt <= 26'd0;
                sel_reg <= sel_cnt;
            end else reg_cnt = reg_cnt + 1'd1;
        end
    end
endmodule
