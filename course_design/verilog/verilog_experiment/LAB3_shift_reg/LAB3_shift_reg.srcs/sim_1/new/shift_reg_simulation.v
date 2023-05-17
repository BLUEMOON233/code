`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/17 22:56:32
// Design Name: 
// Module Name: shift_reg_simulation
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


module shift_reg_simulation(
    );
    reg [1: 0] sel;
    reg [7: 0] D;
    reg nclr, Dsr, Dsl, clk;
    wire [7: 0] out;

    shift_reg sr(
        .sel(sel),
        .D(D),
        .nclr(nclr),
        .Dsr(Dsr),
        .Dsl(Dsl),
        .clk(clk),
        .out(out)
    );

    initial begin
        #0  clk = 1;
            D = 8'b11111111;
            nclr = 1;
            Dsl = 0;
            Dsr = 0;
            sel = 2'b00;
        #10 sel = 2'b11;
        #10 sel = 2'b00;
        #10 sel = 2'b01;
        #10 sel = 2'b01;
        #10 sel = 2'b10;
        #10 sel = 2'b10;
        #10 nclr = 0;
        #10 $finish;
    end
    always #5 clk = ~clk;
endmodule
