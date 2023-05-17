`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 00:52:32
// Design Name: 
// Module Name: counter_mod10_simulation
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


module counter_mod10_simulation(
    );
    reg clk, clr, en;
    wire [3: 0] D;

    counter_mod10 cm(
        .clk(clk),
        .clr(clr),
        .en(en),
        .D(D)
    );

    initial begin
        #0  clk = 1;
            clr = 1;
            en = 1;
        #10 clr = 0;
        #120 en = 0;
        #10 clr = 1;
        #10 $finish;
    end
    always #5 clk = ~clk;

endmodule
