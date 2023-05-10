`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 10:10:45
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

    reg D0, D1, SEL;
    wire Y;

    mux21 m21(
        .D0(D0),
        .D1(D1),
        .SEL(SEL),
        .Y(Y)
    );
    
    initial begin
        #0
        D0 = 0;
        D1 = 0;
        SEL = 0;
        #10
        D0 = 1;
        D1 = 0;
        SEL = 0;
        #10
        D0 = 0;
        D1 = 1;
        SEL = 0;
        #10
        D0 = 1;
        D1 = 1;
        SEL = 0;
        #10
        D0 = 0;
        D1 = 0;
        SEL = 1;
        #10
        D0 = 1;
        D1 = 0;
        SEL = 1;
        #10
        D0 = 0;
        D1 = 1;
        SEL = 1;
        #10
        D0 = 1;
        D1 = 1;
        SEL = 1;
        #10
        $finish;
    end
endmodule
