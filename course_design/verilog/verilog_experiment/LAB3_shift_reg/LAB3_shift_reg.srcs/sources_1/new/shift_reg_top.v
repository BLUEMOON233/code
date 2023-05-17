`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/17 23:15:20
// Design Name: 
// Module Name: shift_reg_top
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


module shift_reg_top(
    input [12: 0] sw,
    input clk,
    output [7: 0] led
    );

    parameter clk_number=26'd50000000;
	reg [25: 0] clk_count = 0;
    reg clk_div = 0;

	always @(posedge clk) begin
		if(clk_count == clk_number) begin
			clk_count <= 0;
			clk_div <= ~clk_div;
		end
        else clk_count <= clk_count + 1;
	end

    shift_reg sr(
        .sel(sw[9: 8]),
        .D(sw[7: 0]),
        .Dsr(sw[11]),
        .Dsl(sw[10]),
        .clk(clk_div),
        .nclr(sw[12]),
        .out(led[7: 0])
    );
endmodule
