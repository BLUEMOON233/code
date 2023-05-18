`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 09:04:29
// Design Name: 
// Module Name: timer
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


module timer(
    input clk, clr, en,
    output [3: 0] d0, d1, d2, d3
    );

    localparam count_value = 10000000;
    reg [23: 0] ms_reg;
    wire ms_tick;
    reg [3: 0] d0_reg, d1_reg, d2_reg, d3_reg;
    reg [3: 0] d0_next, d1_next, d2_next, d3_next;
    
    always @(posedge clk) begin
        if(clr) begin
            ms_reg <= 23'b0;
        end
        else if(en) begin
            d0_reg <= d0_next;
            d1_reg <= d1_next;
            d2_reg <= d2_next;
            d3_reg <= d3_next;
            if(ms_reg < count_value - 1) ms_reg <= ms_reg + 1;
            else ms_reg <= 23'b0;
        end
    end

    assign ms_tick = (ms_reg == count_value - 1) ? 1 : 0;

    always @(posedge ms_tick) begin
        if(d0_reg < 9) d0_next <= d0_reg + 1;
        else begin
            d0_next <= 4'b0000;
            if(d1_reg < 9) d1_next <= d1_reg + 1;
            else begin
                d1_next <= 4'b0000;
                if(d2_reg < 6) d2_next <= d2_reg + 1;
                else begin
                    d2_next <= 4'b0000;
                    if(d3_reg < 9) d3_next <= d3_reg + 1;
                    else d3_next <= 4'b0000;
                end
            end
        end
    end
    
    assign d0 = d0_reg;
    assign d1 = d1_reg;
    assign d2 = d2_reg;
    assign d3 = d3_reg;
endmodule
