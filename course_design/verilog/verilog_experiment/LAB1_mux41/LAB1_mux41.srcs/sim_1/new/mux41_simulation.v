`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 10:23:03
// Design Name: 
// Module Name: mux41_simulation
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


module mux41_simulation(
    );
    reg D0, D1, D2, D3;
    reg [1: 0] SEL;
    wire Y;

    mux41 m41(
        .D0(D0),
        .D1(D1),
        .D2(D2),
        .D3(D3),
        .SEL(SEL),
        .Y(Y)
    );

    initial begin
        #0
        D0 = 0;
        D1 = 0;
        D2 = 0;
        D3 = 0;
        SEL[0] = 0;
        SEL[1] = 0;
        #10
        D0 = 1;
        D1 = 0;
        D2 = 0;
        D3 = 0;
        SEL[0] = 0;
        SEL[1] = 0;
        #10
        D0 = 0;
        D1 = 0;
        D2 = 0;
        D3 = 0;
        SEL[0] = 1;
        SEL[1] = 0;
        #10
        D0 = 0;
        D1 = 1;
        D2 = 0;
        D3 = 0;
        SEL[0] = 1;
        SEL[1] = 0;
        #10
        D0 = 0;
        D1 = 0;
        D2 = 0;
        D3 = 0;
        SEL[0] = 0;
        SEL[1] = 1;
        #10
        D0 = 0;
        D1 = 0;
        D2 = 1;
        D3 = 0;
        SEL[0] = 0;
        SEL[1] = 1;
        #10
        D0 = 0;
        D1 = 0;
        D2 = 0;
        D3 = 0;
        SEL[0] = 1;
        SEL[1] = 1;
        #10
        D0 = 0;
        D1 = 0;
        D2 = 0;
        D3 = 1;
        SEL[0] = 1;
        SEL[1] = 1;
        #10
        $finish;
    end
    
endmodule
