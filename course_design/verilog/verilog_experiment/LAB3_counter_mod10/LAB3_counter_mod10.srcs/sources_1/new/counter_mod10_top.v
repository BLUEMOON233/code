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
    parameter clk_number = 19'd500000;
	reg [18: 0] clk_count = 0;
	reg [17: 0] clk_div2 = 0;
    reg clk_div = 0;

	always @(posedge clk) begin
		if(clk_count == clk_number - 1) begin
			clk_count <= 0;
			clk_div <= ~clk_div;
		end
        else clk_count <= clk_count + 1;
	end
	always @(posedge clk) begin
        clk_div2 <= clk_div2 + 1;
    end

    wire [3: 0] D1, D2, D3, D4;
    wire w1, w2, w3;
    reg [3: 0] D, an_reg;

    counter_mod10 cm1(
        .clk(clk_div),
        .clr(sw[0]),
        .en(sw[1]),
        .D(D1),
        .out(w1)
    );
    counter_mod10 cm2(
        .clk(w1),
        .clr(sw[0]),
        .en(sw[1]),
        .D(D2),
        .out(w2)
    );
    counter_mod10 cm3(
        .clk(w2),
        .clr(sw[0]),
        .en(sw[1]),
        .D(D3),
        .out(w3)
    );
    counter_mod10 cm4(
        .clk(w3),
        .clr(sw[0]),
        .en(sw[1]),
        .D(D4)
    );
    always @(*) begin
        case (clk_div2[17: 16])
            2'b00: an_reg = 4'b1110;
            2'b01: an_reg = 4'b1101;
            2'b10: an_reg = 4'b1011;
            2'b11: an_reg = 4'b0111;
        endcase
    end
    always @(*) begin
        case (clk_div2[17: 16])
            2'b00: D = D1;
            2'b01: D = D2;
            2'b10: D = D3;
            2'b11: D = D4;
        endcase
    end
    assign an = an_reg;
    
    hex7(.D(D), .seg(seg));

endmodule
