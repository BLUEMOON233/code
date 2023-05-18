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
    input clk, clr,
    output [3: 0] d0, d1, d2, d3
    );

    reg [3: 0] d0_reg, d1_reg, d2_reg, d3_reg;
    always @(posedge clk or posedge clr) begin
        if(clr) begin
            d0_reg = 0;
            d1_reg = 0;
            d2_reg = 0;
            d3_reg = 0;
        end
        else if(d0_reg < 9) d0_reg = d0_reg + 1;
        else begin
            d0_reg = 4'b0000;
            if(d1_reg < 9) d1_reg = d1_reg + 1;
            else begin
                d1_reg = 4'b0000;
                if(d2_reg < 5) d2_reg = d2_reg + 1;
                else begin
                    d2_reg = 4'b0000;
                    if(d3_reg < 9) d3_reg = d3_reg + 1;
                    else d3_reg = 4'b0000;
                end
            end
        end
    end
    
    assign d0 = d0_reg;
    assign d1 = d1_reg;
    assign d2 = d2_reg;
    assign d3 = d3_reg;
    
endmodule
