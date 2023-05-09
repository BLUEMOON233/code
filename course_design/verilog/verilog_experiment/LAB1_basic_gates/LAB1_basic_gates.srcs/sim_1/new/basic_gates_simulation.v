`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/10 00:17:51
// Design Name: 
// Module Name: basic_gates_simulation
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


module basic_gates_simulation(
    );
    reg D0, D1;
    wire [6: 0] LED;

    basic_gates bg(
        .D0(D0),
        .D1(D1),
        .LED(LED)
        );
    
    initial begin
        #0
        D0 = 0;
        D1 = 0;
        #10
        D0 = 1;
        D1 = 0;
        #10
        D0 = 0;
        D1 = 1;
        #10
        D0 = 1;
        D1 = 1;
        #10
        $finish;
    end
    
endmodule
