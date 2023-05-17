`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 00:41:33
// Design Name: 
// Module Name: counter_mod10_top
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


module counter_mod10_top(
    input [1: 0] sw,
    input clk,
    output [0: 6] seg,
    output [3: 0] an,
    output dp
    );

    assign dp = 1;
    assign an = 4'b0000;
    parameter clk_number=19'd500000;
	reg [18: 0] clk_count = 0;
    reg clk_div = 0;

	always @(posedge clk) begin
		if(clk_count == clk_number) begin
			clk_count <= 0;
			clk_div <= ~clk_div;
		end
        else clk_count <= clk_count + 1;
	end

    wire [3: 0] D;

    counter_mod10(
        .clk(clk_div),
        .clr(sw[0]),
        .en(sw[1]),
        .D(D)
    );
    hex7(.D(D), .seg(seg));

endmodule
