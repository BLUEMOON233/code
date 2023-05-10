`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/11 00:04:24
// Design Name: 
// Module Name: hex_7_Behavioural_simulation
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


module hex_7_Behavioural_simulation(
    );
    reg [3: 0] in;
    wire [6: 0] out;

    hex_7_Behavioural h7d(.D(in), .seg(out));

    initial begin
        #0  in = 0;
        #10 in = 1;
        #10 in = 2;
        #10 in = 3;
        #10 in = 4;
        #10 in = 5;
        #10 in = 6;
        #10 in = 7;
        #10 in = 8;
        #10 in = 9;
        #10 in = 10;
        #10 in = 11;
        #10 in = 12;
        #10 in = 13;
        #10 in = 14;
        #10 in = 15;
        #10 $finish;
    end

endmodule
