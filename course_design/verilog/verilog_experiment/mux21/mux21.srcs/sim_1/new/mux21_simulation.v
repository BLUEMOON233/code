`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/08 22:20:34
// Design Name: 
// Module Name: mux21_simulation
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


module mux21_simulation(
    );
    reg d0, d1, sel;
    wire led;
    mux21a test(
        .d0(d0),
        .d1(d1),
        .sel(sel),
        .led(led)
    );
    initial begin
        #0      sel = 0;
                d1 = 0;
                d0 = 0;
        #100    sel = 0;
                d1 = 0;
                d0 = 1;
        #100    sel = 0;
                d1 = 1;
                d0 = 0;
        #100    sel = 0;
                d1 = 1;
                d0 = 1;
        #100    sel = 1;
                d1 = 0;
                d0 = 0;
        #100    sel = 1;
                d1 = 0;
                d0 = 1;
        #100    sel = 1;
                d1 = 1;
                d0 = 0;
        #100    sel = 1;
                d1 = 1;
                d0 = 1;
        #100 $finish;
    end
endmodule
